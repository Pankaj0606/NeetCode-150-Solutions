# Evaluate Reverse Polish Notation (LeetCode 150)

## Problem Statement & Core Challenges
Given an array of strings `tokens` that represent an arithmetic expression in **Reverse Polish Notation (RPN)**, evaluate the expression and return the integer result.

- Each token is either an integer (may be negative) or one of the four operators `+`, `-`, `*`, `/`.
- The division between two integers should truncate toward zero.
- The input is guaranteed to be a valid RPN expression.

**Core challenges**:
1. **Order of operands** – In RPN the operator works on the two *most recent* numbers, not the two surrounding ones.
2. **Efficiently accessing the last two operands** – A stack (LIFO) naturally models this.
3. **Handling edge‑cases** such as single‑element input, negative numbers, and division truncation.

---

## Approaches
We present three progressively better solutions for **both C++ and Java**.

### 1️⃣ Brute‑Force (Quadratic Time)
**Idea** – Repeatedly scan the token list, locate the first operator, compute the result of the two preceding numbers, replace the three tokens with the computed value, and continue until only one token remains.

- **Time Complexity**: `O(n²)` – each scan may touch the whole list and we perform up to `n/2` scans.
- **Space Complexity**: `O(1)` extra (we mutate the original vector/ArrayList).
- **When to use** – Rarely in production, but useful to illustrate the *naïve* thinking process during an interview.

### 2️⃣ Better (Linear Time, Stack)
**Idea** – Use a stack. Iterate once over `tokens`. When we see a number, push it. When we see an operator, pop the top two numbers, apply the operator, and push the result back.

- **Time Complexity**: `O(n)` – each token is processed once.
- **Space Complexity**: `O(n)` – worst‑case the stack holds all numbers.
- **Why it’s better** – Directly models the LIFO nature of RPN and avoids repeated scans.

### 3️⃣ Optimal (Linear Time, In‑Place Stack)
**Idea** – The stack from the previous approach is already optimal in asymptotic terms. We can shave constant factors by:
- Pre‑allocating the stack array (`vector<int>` in C++ or `int[]` in Java) to avoid dynamic resizing.
- Using an integer index (`top`) instead of `push_back/pop_back` (C++) or `Stack<Integer>` (Java) to eliminate method‑call overhead.

- **Time Complexity**: `O(n)`.
- **Space Complexity**: `O(n)` but with a smaller constant factor.
- **When to discuss** – Mention that the “optimal” solution is still the stack‑based linear algorithm; the extra micro‑optimisations show attention to detail.

---

## Transitioning From Brute‑Force to Optimal in an Interview
1. **Start with the obvious** – Explain the scan‑replace idea, show a quick prototype, and point out its `O(n²)` nature.
2. **Identify the bottleneck** – The repeated linear scans are the culprit.
3. **Introduce a data structure** – Recognise that we always need the *most recent* two numbers → a **stack**.
4. **Show the stack algorithm** – Walk through a small example, emphasizing push/pop order.
5. **Fine‑tune** – Mention pre‑allocation and index‑based pushes to reduce overhead, concluding with the optimal version.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters | How we handle it |
|-----------|----------------|-----------------|
| Single token (e.g., `["42"]`) | Guarantees we don’t pop from an empty stack. | Return the parsed integer directly; stack stays empty. |
| Negative numbers (`"-11"`) | Parsing must accept the leading `-`. | Use `stoi`/`Integer.parseInt`. |
| Division truncation (`"6","-132","/"`) | C++ integer division truncates toward zero, Java does the same. | Perform `a / b` directly (both languages follow the spec). |
| Large input size (up to 10⁴ tokens) | Tests time‑/space efficiency. | Stack solution is `O(n)` and fits easily. |
| All operators first (invalid) – not given by problem constraints, but good to mention defensive checks. |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this without extra space?*  
**A:** Not in the strict sense; we need to remember the last two operands. The in‑place stack uses `O(n)` auxiliary space, which is optimal for this problem.

**Q2:** *What if the division operator should round up instead of truncating?*  
**A:** Adjust the division step: `int res = a / b; if ((a ^ b) < 0 && a % b != 0) res++;` – this forces ceiling for negative results.

**Q3:** *How would you extend this to support exponentiation (`^`) or unary operators?*  
**A:** Add a case for `^` that pops two operands and pushes `pow(a,b)`. For unary operators (e.g., `neg`), pop one operand, apply the operation, and push back.

**Q4:** *Is there a way to evaluate the expression in a single pass without a stack?*  
**A:** Only if we know the expression depth ahead of time (e.g., using recursion on a pointer). Recursion implicitly uses the call stack, which is equivalent to an explicit stack.

---

**Happy coding!**
