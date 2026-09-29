# Valid Palindrome

## Problem Statement
Given a string `s`, determine if it is a palindrome **considering only alphanumeric characters** and **ignoring cases**. Return `true` if it is a palindrome, otherwise return `false`.

**Example**
```text
Input:  "A man, a plan, a canal: Panama"
Output: true
Explanation: After removing non‑alphanumeric characters and converting to lower case, we get "amanaplanacanalpanama" which reads the same forward and backward.
```

## Core Challenges
1. **Filtering** – We must ignore spaces, punctuation, and any non‑alphanumeric symbols.
2. **Case Insensitivity** – Upper‑case and lower‑case letters are considered equal.
3. **In‑Place vs Extra Space** – Interviewers love to see a solution that works in O(1) extra space.
4. **Edge Cases** – Empty strings, strings with only non‑alphanumeric characters, and very long inputs.

## Approaches
### 1️⃣ Brute‑Force (O(n) time, O(n) space)
* Build a new string containing only the alphanumeric characters in lower case.
* Compare this filtered string with its reverse.
* Straightforward and easy to explain, but uses linear extra memory.

### 2️⃣ Two‑Pointer (O(n) time, O(1) space)
* Use two indices (`left` and `right`) starting at the ends of the original string.
* Move each pointer inward while skipping non‑alphanumeric characters.
* Compare the lower‑cased characters; if any mismatch occurs, return `false`.
* No additional containers – constant extra space.

### 3️⃣ Optimized Two‑Pointer (O(n) time, O(1) space, minimal overhead)
* Same logical flow as the previous approach but avoids repeated function calls and extra bounds checks.
* In C++ we can work directly on a `const string&` and use `size_t` indices.
* In Java we convert the input to a `char[]` once, which is faster than repeated `charAt` calls.
* This is the *optimal* solution you would ship in production.

## Transition Explanation (Brute‑Force → Optimal)
1. **Identify the bottleneck** – The extra string allocation in the brute‑force solution costs O(n) memory.
2. **Introduce two pointers** – By scanning from both ends we can compare characters on‑the‑fly, eliminating the need for a filtered copy.
3. **Refine the pointer loop** – Skip non‑alphanumerics in a tight `while` loop and perform case conversion only when needed.
4. **Micro‑optimise** – In C++ use `std::tolower`/`std::isalnum` on `unsigned char` to avoid UB; in Java cache the `char[]` to avoid repeated `charAt` overhead.
5. **Result** – Same O(n) time, but O(1) auxiliary space and lower constant factors.

## Edge Cases Interviewers Love
| Input | Reason it’s Tricky |
|-------|--------------------|
| `""` (empty) | Should return `true` – an empty string is a palindrome.
| `".,!"` | No alphanumeric characters; after filtering the string is empty → `true`.
| Very long string (10⁶+ chars) | Tests that you don’t use O(n) extra memory and that your loop is truly O(n).
| Unicode letters outside ASCII | LeetCode restricts to ASCII, but you can mention using `isalnum`/`isLetterOrDigit` which handle Unicode in Java.
| Mixed case with numbers `"0P"` | After filtering → `"0p"` which is not a palindrome.

## Mock Interview Follow‑up Q&A
**Q1:** *Can we solve this without using any library functions like `isalnum` or `tolower`?*  
**A:** Yes. Check character ranges manually (`'a'‑'z'`, `'A'‑'Z'`, `'0'‑'9'`) and convert upper‑case to lower‑case by adding `32` (`c | 32`). This shows you understand ASCII encoding.

**Q2:** *What is the time complexity if the input string contains only non‑alphanumeric characters?*  
**A:** The algorithm still scans the entire string once, so it remains O(n). The inner skip loops run but each character is visited at most twice.

**Q3:** *How would you adapt the solution for Unicode where case folding is more complex?*  
**A:** In Java you could use `Character.toLowerCase` which handles Unicode case folding. In C++ you would need a library like ICU or convert to a normalized UTF‑8 string and compare code points.

**Q4:** *If the string is stored in a read‑only memory region, can we still achieve O(1) space?*  
**A:** Yes. The two‑pointer method only reads characters; it never writes to the original buffer, so it works on read‑only data.

---
*Feel free to copy the code snippets below into your IDE and run the provided test cases.*
