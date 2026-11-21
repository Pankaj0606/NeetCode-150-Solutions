# Generate Parentheses

## Problem Statement
Given `n` pairs of parentheses, write a function to generate **all** combinations of well‑formed (i.e., valid) parentheses.

**Input:** `int n` – the number of pairs.
**Output:** `List<String>` (or `vector<string>` in C++) containing every distinct valid string of length `2*n`.

### Core Challenges
1. **Exponential Search Space** – There are `2^(2n)` possible strings of '(' and ')'. Only a tiny fraction are valid.
2. **Ensuring Balance** – While constructing a string we must never allow more closing than opening parentheses.
3. **Avoid Duplicates** – The generation method should produce each combination exactly once.

---

## Approaches

### 1️⃣ Brute‑Force (Generate‑All‑and‑Filter)
*Generate every possible sequence of length `2n` and keep only the ones that are balanced.*

**Algorithm**
1. Recursively fill a character array of size `2n` with '(' or ')'.
2. When the array is full, run a linear validity check (balance counter).
3. If valid, add to the result list.

**Complexities**
- **Time:** `O(2^(2n) * n)` – we enumerate `2^(2n)` strings and each validation costs `O(n)`.
- **Space:** `O(2n)` recursion stack + result size (`O(Catalan(n) * n)`).

**When to discuss** – Good for showing you understand the naive search space before pruning.

---

### 2️⃣ DP / Catalan Construction (Intermediate Optimization)
The number of valid strings for `n` is the *n‑th Catalan number*. We can build the answer for `n` from answers of smaller sub‑problems:

```
result[n] = for i = 0 .. n-1:
                for each left in result[i]:
                    for each right in result[n-1-i]:
                        "(" + left + ")" + right
```

**Complexities**
- **Time:** `O(C_n * n)` where `C_n` is the n‑th Catalan number (still optimal asymptotically but with extra concatenation work).
- **Space:** `O(C_n * n)` for storing all intermediate lists.

**When to discuss** – Demonstrates knowledge of Catalan numbers and DP, and shows a clear improvement over brute‑force without yet using backtracking.

---

### 3️⃣ Backtracking with Pruning (Optimal Approach)
We build the string **incrementally**, keeping two counters:
- `open` – how many '(' we can still place.
- `close` – how many ')' we can still place **and** must never be placed when `close <= open` (otherwise we would close before opening).

**Algorithm**
1. Start with an empty string, `open = n`, `close = n`.
2. If `open > 0`, append '(' and recurse with `open‑1`.
3. If `close > open`, append ')' and recurse with `close‑1`.
4. When both counters reach 0, we have a valid combination.

**Complexities**
- **Time:** `O(C_n)` – each valid combination is produced exactly once; the work per combination is `O(n)` for string building, giving `O(C_n * n)` which is optimal for this problem.
- **Space:** `O(n)` recursion stack + output size.

**When to discuss** – This is the go‑to solution in interviews. It shows you can prune the search space early and reason about correctness.

---

## Transition Narrative (Brute‑Force → Optimal)
1. **State the brute‑force** and point out its `2^(2n)` blow‑up.
2. **Introduce the invariant**: at any prefix, `#('(') >= #(')')`. This lets us discard half the branches immediately.
3. **Show the pruning rule** (`close > open`) and rewrite the recursion to use two counters.
4. **Highlight that** we now generate only the `C_n` valid strings, which is the theoretical lower bound.
5. Optionally, mention the DP formulation as a *different* way to achieve the same bound.

---

## Edge‑Case Checklist (Interviewers love these)
| Edge case | Why it matters | Expected handling |
|-----------|----------------|-------------------|
| `n = 0`   | Empty input – should return `[""]` (one empty combination). |
| `n = 1`   | Base case – only `"()"`. |
| Large `n` (e.g., 8‑10) | Tests exponential blow‑up; only optimal/back‑track should finish quickly. |
| Memory limits | Ensure you don’t store all `2^(2n)` candidates. |

---

## Mock Interview Follow‑up Q&A
1. **Q:** *Can we generate the strings in lexicographic order?*  
   **A:** Yes. The backtracking approach that always tries '(' before ')' naturally yields lexicographic order.
2. **Q:** *How would you modify the algorithm to return the k‑th combination without generating all of them?*  
   **A:** Use the Catalan DP to count how many strings start with a particular prefix and skip whole sub‑trees until the k‑th is reached (similar to “k‑th permutation” technique).
3. **Q:** *What is the relationship between this problem and the Catalan numbers?*  
   **A:** The number of valid parentheses strings for `n` pairs equals the n‑th Catalan number `C_n = (1/(n+1))*binom(2n, n)`. Both DP and backtracking generate exactly `C_n` results.
4. **Q:** *If we were asked to generate parentheses with three types of brackets – `()`, `[]`, `{}` – how would the solution change?*  
   **A:** The state space grows; we need a counter for each type and the invariant that at any point the closing bracket must match the most recent unmatched opening bracket (i.e., use a stack). The backtracking still works but with `3n` total characters and more branching.

---

## TL;DR
* Brute‑force: generate all `2^(2n)` strings → filter → **O(2^(2n)·n)**.
* DP (Catalan): build from smaller results → **O(C_n·n)**, extra memory for intermediate lists.
* Backtracking with `open/close` counters: prune early → **O(C_n·n)** time, **O(n)** extra space – the optimal interview solution.
