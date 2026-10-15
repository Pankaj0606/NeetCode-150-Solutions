# Minimum Window Substring

## Problem Statement
Given two strings **s** and **t**, return the minimum window in **s** which will contain all the characters in **t** (including duplicates). If there is no such window, return the empty string ``""``.

### Example
```
Input:  s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
```

## Core Challenges
1. **Character Frequency** – We must account for duplicate characters in *t*.
2. **Finding the *minimum* window** – Not just any window, but the *shortest* one.
3. **Linear‑time requirement** – Brute‑force is O(n³) and unacceptable for large inputs.

---

## Approaches
### 1️⃣ Brute‑Force (O(n³) time, O(1) extra space)
Enumerate every possible substring of **s**, check if it contains all characters of **t** using a frequency map, and keep the smallest valid one.

### 2️⃣ Better Sliding‑Window with Fixed‑Size Arrays (O(n·|Σ|) ≈ O(n) time, O(1) space)
* Use two integer arrays of size 128 (ASCII) to store required and current counts.
* Expand the right pointer, decreasing a *required* counter when we satisfy a needed character.
* When *required* reaches zero, contract from the left to shrink the window while it stays valid.
* This eliminates the O(n³) enumeration but still checks the whole alphabet on each step.

### 3️⃣ Optimal Sliding‑Window with HashMaps (O(n) time, O(|t|) space)
* Store only the characters that actually appear in **t** in a hashmap `need`.
* Maintain another hashmap `window` for the current window frequencies.
* Keep a `formed` counter that tells how many distinct characters have met their required frequency.
* When `formed == need.size()`, the window is valid – try to contract it.
* This is the classic LeetCode optimal solution and runs in linear time.

---

## Complexity Analysis
| Approach | Time | Extra Space |
|----------|------|-------------|
| Brute‑Force | O(n³) – enumerate all substrings and verify each | O(1) (or O(|t|) for the frequency map) |
| Better Sliding‑Window | O(n·|Σ|) ≈ O(n) – each character processed a constant number of times | O(1) – fixed‑size arrays |
| Optimal Sliding‑Window | O(n) – each character enters and leaves the window once | O(|t|) – hashmap for needed characters |

---

## How to Explain the Transition in an Interview
1. **Start with the obvious** – “I would try every substring and check if it contains *t*.” Show the O(n³) reasoning.
2. **Identify the bottleneck** – The repeated *contains* check is expensive.
3. **Introduce the sliding‑window idea** – “We can move a right pointer to grow a candidate window and a left pointer to shrink it when it becomes valid.”
4. **Show the first improvement** – Use fixed‑size frequency arrays; this reduces the *contains* check to O(1) per step, giving O(n) overall but still scanning the whole alphabet.
5. **Push further** – Realise we only need to track characters that appear in *t*. Replace the arrays with hashmaps and a `formed` counter, cutting the constant factor and making the solution truly optimal.
6. **Summarize** – The final algorithm is linear time, linear in the size of *t* for extra space, and works for any character set.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters |
|-----------|----------------|
| `t` longer than `s` | No window can exist – should return ``""`` quickly. |
| Repeated characters in `t` (e.g., ``"AA``) | Frequency handling must be correct. |
| Characters in `t` not present in `s` | Immediate ``""`` result. |
| Multiple minimal windows of the same length | Return the *first* (left‑most) one – our algorithm naturally does this. |
| Empty strings | Both inputs empty → ``""``; only `t` empty → ``""`` (by definition). |

---

## Mock Interview Follow‑up Q&As
**Q1.** *Can we solve this problem without extra space?*  
**A:** Not really – we need to remember the required frequencies of characters in `t`. The optimal solution uses O(|t|) extra space, which is optimal because the output itself can be that large.

**Q2.** *What if the input strings contain Unicode characters beyond ASCII?*  
**A:** Switch the fixed‑size arrays to an unordered_map (or use a larger array if the code‑point range is known). The optimal hashmap‑based solution already works for any Unicode set.

**Q3.** *How would you modify the algorithm to return **all** minimum windows instead of just one?*  
**A:** After finding the length of the smallest window, run a second pass with the same sliding‑window logic, collecting every window whose length equals the minimum.

**Q4.** *Is it possible to solve this problem in a single pass without the inner while‑loop that contracts the window?*  
**A:** The contraction step is essential; without it we cannot guarantee minimality. Any linear solution must have a two‑pointer structure where the left pointer moves conditionally.

---

## TL;DR
* Brute‑Force – enumerate all substrings (O(n³)).
* Better – sliding window with fixed arrays (O(n) time, O(1) space).
* Optimal – sliding window with hashmaps and a `formed` counter (O(n) time, O(|t|) space).
* In an interview, walk the interviewer through the evolution of ideas, justify each optimisation, and discuss edge cases.
