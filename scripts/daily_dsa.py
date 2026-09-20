import os
import sys
import json
import re
import time
import gspread
from dotenv import load_dotenv
from groq import Groq

load_dotenv()

GROQ_API_KEY = os.getenv("GROQ_API_KEY")
if not GROQ_API_KEY:
    print("✗ Error: GROQ_API_KEY is missing!")
    sys.exit(1)

def sanitize_filename(name: str) -> str:
    """Removes invalid filesystem characters."""
    return re.sub(r'[\\/*?:"<>|]', "", name).strip().replace(" ", "_")

def connect_to_sheet():
    """Connects to Google Sheets with exponential retry."""
    for attempt in range(1, 4):
        try:
            gc = gspread.service_account(filename="credentials.json")
            sh = gc.open("DSA_Instagram_Automation")
            worksheet = sh.get_worksheet(0)
            return worksheet
        except Exception as e:
            print(f"⚠ Attempt {attempt}/3 connecting to Google Sheets failed: {e}")
            time.sleep(4)
    sys.exit("✗ Could not connect to Google Sheets.")

def generate_dsa_bundle(question_name: str, topic: str, link: str):
    """Generates LeetCode-compliant C++ and Java code along with an interview README."""
    client = Groq(api_key=GROQ_API_KEY)
    
    prompt = f"""
You are a Staff Software Engineer and Senior Technical Interviewer at a FAANG company.
Solve this DSA problem thoroughly:
- Problem: {question_name}
- Topic: {topic}
- Reference Link: {link}

Generate complete, ready-to-submit implementations (LeetCode/NeetCode style with standard class and method signatures) in both C++ and Java.
Provide 3 approaches for each language:
1. Worst / Brute Force
2. Better / Intermediate Optimization
3. Best / Optimal Approach

Also write an exhaustive interview-focused README.md covering:
- Problem statement & core challenges
- Walkthrough of each approach with Time and Space complexity analysis
- How to explain the transition from Brute Force to Optimal during an interview
- Edge cases interviewers love to test
- 3 to 4 Mock Interview Follow-up Q&As

Output MUST be a single valid JSON object strictly matching this schema:
{{
  "readme_markdown": "Complete formatted Markdown string for the README.md",
  "cpp_brute_force": "Compilable C++ code for brute force approach",
  "cpp_better": "Compilable C++ code for better approach",
  "cpp_optimal": "Compilable C++ code for optimal approach",
  "java_brute_force": "Compilable Java code for brute force approach",
  "java_better": "Compilable Java code for better approach",
  "java_optimal": "Compilable Java code for optimal approach"
}}
"""
    # Candidate models in order of capability on Groq
    candidate_models = ["openai/gpt-oss-120b", "openai/gpt-oss-20b", "llama-3.1-8b-instant"]

    for model_name in candidate_models:
        try:
            print(f"🤖 Attempting generation with model: {model_name}...")
            response = client.chat.completions.create(
                messages=[
                    {
                        "role": "system",
                        "content": (
                            "You are a specialized code generation engine. "
                            "You must output only a valid raw JSON object strictly adhering to the requested schema. "
                            "Do not wrap your answer in markdown tags."
                        )
                    },
                    {"role": "user", "content": prompt}
                ],
                model=model_name,
                response_format={"type": "json_object"},
                max_tokens=6000,
                temperature=0.2
            )

            raw_text = response.choices[0].message.content

            # Safety cleanup: strip any model <think> reasoning tags if present
            if "<think>" in raw_text and "</think>" in raw_text:
                think_end = raw_text.find("</think>")
                raw_text = raw_text[think_end + len("</think>"):].strip()

            start_idx = raw_text.find("{")
            end_idx = raw_text.rfind("}")
            if start_idx != -1 and end_idx != -1:
                clean_json_str = raw_text[start_idx:end_idx+1]
                return json.loads(clean_json_str)

        except Exception as err:
            print(f"⚠ Model {model_name} failed: {err}")
            print("  Trying next fallback model...")

    sys.exit("✗ All candidate models failed to generate valid DSA solutions.")

def update_root_readme(topic: str, question: str, relative_path: str):
    """Appends the newly solved problem to the root index table."""
    root_readme = "README.md"
    entry = f"| {topic} | [{question}](./{relative_path}) | ✅ Completed |\n"

    if not os.path.exists(root_readme) or os.stat(root_readme).st_size == 0:
        initial_content = (
            "# 🚀 NeetCode 150 Daily Solutions\n\n"
            "An automated repository archiving daily Data Structures & Algorithms solutions "
            "in C++ and Java, featuring Worst, Better, and Optimal approaches with interview breakdown notes.\n\n"
            "| Topic | Problem | Status |\n"
            "| :--- | :--- | :--- |\n"
        )
        with open(root_readme, "w", encoding="utf-8") as f:
            f.write(initial_content)

    with open(root_readme, "a", encoding="utf-8") as f:
        f.write(entry)

def main():
    print("📡 Fetching question from Google Sheets...")
    worksheet = connect_to_sheet()
    records = worksheet.get_all_records()
    headers = worksheet.row_values(1)

    if "Github Status" not in headers:
        sys.exit("✗ 'Github Status' column not found in Google Sheet. Please add it.")
    status_col_idx = headers.index("Github Status") + 1

    pending_rows = [(idx + 2, r) for idx, r in enumerate(records) if str(r.get("Github Status", "")).strip() == "Pending"]
    if not pending_rows:
        print("✓ All problems are completed! No pending questions found.")
        return

    row_num, row_data = pending_rows[0]
    question_name = row_data.get("Question Name")
    topic = row_data.get("Topic")
    link = row_data.get("NeetCode Link", "")

    print(f"🎯 Processing [{topic}]: {question_name}")

    # Generate content
    data = generate_dsa_bundle(question_name, topic, link)

    # Prepare directories
    safe_topic = sanitize_filename(topic)
    safe_qname = sanitize_filename(question_name)
    target_dir = os.path.join(safe_topic, safe_qname)
    os.makedirs(target_dir, exist_ok=True)

    # Write code files
    files_to_write = {
        "README.md": data["readme_markdown"],
        "1_BruteForce.cpp": data["cpp_brute_force"],
        "2_Better.cpp": data["cpp_better"],
        "3_Optimal.cpp": data["cpp_optimal"],
        "1_BruteForce.java": data["java_brute_force"],
        "2_Better.java": data["java_better"],
        "3_Optimal.java": data["java_optimal"]
    }

    def format_code(text: str) -> str:
        """Converts literal escaped newlines and tabs into real multi-line code."""
        if not isinstance(text, str):
            return ""
        # If the LLM returned literal '\n' instead of actual newlines
        if "\\n" in text:
            text = text.replace("\\r\\n", "\n").replace("\\n", "\n").replace("\\t", "    ")
        return text.strip() + "\n"

    for filename, content in files_to_write.items():
        filepath = os.path.join(target_dir, filename)
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content.strip() + "\n")
        print(f"  └── Created: {filepath}")

    # Update root index tracker
    update_root_readme(topic, question_name, target_dir)
    print("✓ Root README.md progress table updated!")

    # Update status in Google Sheets
    worksheet.update_cell(row_num, status_col_idx, "Completed")
    print(f"✓ Google Sheet row {row_num} marked as 'Completed'!")

if __name__ == "__main__":
    main()