# Longest Repeating Character Replacement

## Problem Statement
Given a string `s` consisting of only uppercase English letters, you can replace at most **one** character with any other uppercase letter. Return the length of the longest substring containing the same letter after performing the replacement.

## Core Challenges
- Recognize that the problem is a *sliding window* where the window size can be expanded as long as the number of characters that need to be changed does not exceed the allowed limit (1).
- Maintaining the frequency of characters inside the window efficiently.
- Transitioning from a naïve O(N²) solution to an O(N) solution without recomputing the maximum frequency from scratch each step.

## Approaches

### 1. Brute‑Force (O(N³) / O(N²) depending on implementation)
Enumerate every possible substring, count character frequencies, and check if the substring can be turned into a repeating character with ≤1 replacement.

**Time:** O(N³) (enumerate O(N²) substrings and count 26 letters each)  
**Space:** O(1)

### 2. Better Sliding Window (O(26·N) ≈ O(N))
Use a sliding window and a frequency array of size 26. After each expansion we recompute the current maximum frequency by scanning the array.

**Time:** O(26·N) → O(N)  
**Space:** O(26) → O(1)

### 3. Optimal Sliding Window (O(N))
Keep a running `maxCount` – the count of the most frequent character **ever** seen in the current window. The window is valid while `windowSize - maxCount ≤ 1`. If it becomes invalid we shrink from the left. This avoids the O(26) scan.

**Time:** O(N)  
**Space:** O(1)

## How to Explain the Transition in an Interview
1. **Start with brute force** – show you understand the definition of a valid substring.
2. **Identify the bottleneck** – recomputing the max frequency for every window is expensive.
3. **Introduce a sliding window** – we only move the right pointer forward, shrinking left only when the constraint is broken.
4. **Optimize the max‑frequency lookup** – maintain it incrementally; argue that it may be slightly stale but never underestimates the true max, which is sufficient for correctness.
5. **Conclude with O(N) solution** – highlight constant‑space usage and linear time.

## Edge Cases Interviewers Love
- Empty string (`""`) → answer `0`.
- All characters already the same (`"AAAAA"`).
- No possible replacement improves the answer (`"ABCDEF"`).
- String length `1`.
- Very long string (10⁵) to test O(N) vs O(N²).

## Mock Interview Follow‑up Q&A

| Question | Expected Insight |
|----------|------------------|
| *What if we are allowed to replace **k** characters instead of 1?* | Generalize the condition to `windowSize - maxCount ≤ k`. The same O(N) algorithm works. |
| *Can we solve it without extra space?* | The frequency array of size 26 is already O(1). Any solution needs to know counts of characters, so constant extra space is optimal. |
| *Why is it safe to keep `maxCount` as the historical maximum instead of recomputing?* | Because shrinking the window never increases the true max frequency; the stored `maxCount` may be larger than the current window’s max, which only makes the condition stricter, never allowing an invalid window to be considered valid. |
| *How would you adapt the solution for lowercase letters or Unicode?* | Increase the size of the frequency container (e.g., 128 for ASCII, a hashmap for Unicode) while keeping the same logic. |
| *What is the overall time complexity if we used a hashmap for frequencies?* | Still O(N) amortized, but with a larger constant factor due to hashmap operations. |

---

Feel free to copy the implementations below into your IDE and run the provided test cases.

```
