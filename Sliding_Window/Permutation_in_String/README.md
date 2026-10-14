# Permutation in String (LeetCode 567)

## Problem Statement
Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`. In other words, one of the first string's permutations is a substring of the second string.

**Example**
```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true  // "ba" is a permutation of "ab" and appears in s2
```

## Core Challenges
1. **Character frequency matching** – we need to know whether a window of `s2` has exactly the same multiset of characters as `s1`.
2. **Efficient sliding** – checking every possible window naïvely leads to O(|s1|·|s2|) time, which is too slow for large inputs.
3. **Constant‑time window update** – the optimal solution updates the state in O(1) when the window moves by one character.

---

## Approaches
### 1️⃣ Brute‑Force (O(|s1|·|s2|) time, O(1) extra space)
* Iterate over every possible start index `i` in `s2` where a window of length `|s1|` fits.
* Build a frequency array for the window and compare it with the frequency array of `s1`.
* If any window matches, return `true`.

**Pros** – simple, easy to explain.
**Cons** – recomputes the whole frequency array for each window → quadratic time.

### 2️⃣ Better / Intermediate (O(26·|s2|) ≈ O(|s2|) time, O(1) space)
* Keep a single frequency array `cnt` that stores `cnt[c] = frequency_in_s1 - frequency_in_current_window`.
* As we slide the window, decrement the count for the incoming character and increment for the outgoing character (once the window size exceeds `|s1|`).
* After each slide, scan the 26‑element array to see if all entries are zero.
* The scan costs a constant 26 operations, so the overall complexity is linear.

**Pros** – still O(|s2|) but easier to understand than the optimal match‑counter trick.
**Cons** – the 26‑element scan is a hidden constant factor.

### 3️⃣ Optimal (O(|s2|) time, O(1) space)
* Use the same `cnt` array as above, but maintain a variable `matches` that counts how many characters currently have `cnt[i] == 0`.
* When a character enters or leaves the window we update `cnt` **and** adjust `matches` in O(1).
* If `matches == 26` at any point, the window is a permutation of `s1`.

**Pros** – true linear time with only O(1) extra work per slide.
**Cons** – slightly more bookkeeping; interviewers love to see you reason about the `matches` invariant.

---

## From Brute‑Force to Optimal – How to Explain in an Interview
1. **Start with the definition** – we need to compare character multisets.
2. **Show the naïve O(n·m) solution** – build a frequency map for each window.
3. **Identify the repeated work** – the frequency map of overlapping windows shares most characters.
4. **Introduce a sliding window** – update the map incrementally instead of rebuilding.
5. **Observe the constant‑size alphabet** – we can store counts in a fixed‑size array (size 26 for lowercase letters).
6. **Reduce the O(26) scan** – keep a `matches` counter that tells us instantly whether all counts are zero.
7. **Result** – we end up with O(|s2|) time and O(1) space, which is optimal for this problem.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters |
|-----------|----------------|
| `s1` longer than `s2` | Immediate `false` – must be handled before any sliding. |
| Repeated characters, e.g. `s1 = "aa"`, `s2 = "aaaa"` | Guarantees the algorithm correctly handles counts > 1. |
| Empty strings (though LeetCode guarantees non‑empty) | Shows defensive coding. |
| All same character, e.g. `s1 = "aaa"`, `s2 = "bbb"` | Tests that the algorithm does not give false positives. |
| Large input size (10⁵+) | Confirms linear solution is required. |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this problem without extra space?*  
**A:** Yes. Because the alphabet size is constant (26), the frequency array itself is O(1) space. The optimal solution only uses that array and a few integers.

**Q2:** *What if the strings contain Unicode characters?*  
**A:** The fixed‑size array no longer works. We would fall back to a hashmap (`unordered_map<char,int>` in C++ or `Map<Character,Integer>` in Java). The algorithmic idea stays the same, but space becomes O(k) where `k` is the number of distinct characters.

**Q3:** *How would you modify the solution to return the start index of the permutation instead of a boolean?*  
**A:** As soon as `matches == 26` (or the frequency arrays are equal) we can return `left` (the current window's start). If none is found, return `-1`.

**Q4:** *Is there a way to solve this with a rolling hash?*  
**A:** Yes, but because the alphabet is small, a frequency‑based sliding window is simpler and avoids hash collisions. A rolling hash would be O(|s2|) but adds complexity and potential false positives.

---

**Bottom line:** Master the transition from brute‑force to the constant‑time sliding‑window with a match counter – it demonstrates both algorithmic insight and practical coding skill.
