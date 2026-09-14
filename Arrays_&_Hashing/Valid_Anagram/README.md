# Valid Anagram
## Problem Statement & Core Challenges
Given two strings `s` and `t`, determine if `t` is an anagram of `s`.  An anagram means both strings contain the **exact same characters** with the **exact same frequencies**, only the order may differ.

Key challenges interviewers love to probe:
- Handling different string lengths early.
- Choosing the right data structure for counting characters.
- Discussing trade‑offs between time, space, and code simplicity.
- Extending the solution to Unicode or case‑insensitive scenarios.

---
## Approaches
### 1️⃣ Brute‑Force (Quadratic)
**Idea**: For each character in `s` scan `t` to find a matching, unused character.

**Complexities**
- Time: **O(n²)** – nested loops.
- Space: **O(1)** (aside from a visited boolean array of size *n*).

**When to use**: Demonstrates baseline thinking, useful when you haven't yet considered hashing or sorting.

---
### 2️⃣ Better – Sorting (n log n)
**Idea**: Sort both strings and compare them character‑by‑character.

**Complexities**
- Time: **O(n log n)** – dominated by the sort.
- Space: **O(1)** if the language sorts in‑place, otherwise **O(n)** for the sorted copies.

**Why it’s better**: Eliminates the inner loop, leverages well‑optimized library sorts, and is easy to explain.

---
### 3️⃣ Optimal – Counting (Linear)
**Idea**: Use a fixed‑size frequency array (26 for lowercase English letters) to count characters in `s` and decrement while scanning `t`.

**Complexities**
- Time: **O(n)** – single pass over each string.
- Space: **O(1)** – constant 26‑element array (or 128/256 for full ASCII).

**Best for interview**: Shows mastery of hashing/counting techniques and constant‑space optimization.

---
## Transition Narrative (Brute → Optimal)
1. **Start with the naive double‑loop** to prove you understand the definition.
2. **Ask about constraints** – if strings can be large, O(n²) is unacceptable.
3. **Introduce sorting** as a natural improvement (O(n log n)).
4. **Probe further** – “Can we do better than sorting?” – leads to counting/hashing.
5. **Present the counting array** – constant‑time look‑ups, linear scan, and discuss extensions (Unicode → hashmap).

---
## Edge Cases Interviewers Love
- Empty strings: `"", ""` → `true`.
- Different lengths: early `false`.
- Strings with non‑alphabetic characters or mixed case – clarify assumptions.
- Very long strings (10⁵+ chars) to test performance.
- Unicode characters – would require a `Map<Character,Integer>` instead of a fixed array.

---
## Mock Interview Follow‑up Q&As
**Q1:** *What if the input can contain any Unicode character?*  
**A:** Switch the fixed array to a `HashMap<Character,Integer>` (or `int[128]` for ASCII). Time stays O(n); space becomes O(k) where *k* is the number of distinct characters.

**Q2:** *Can we solve it without extra space?*  
**A:** Sorting in‑place gives O(1) auxiliary space, but still O(n log n) time. True O(1) time‑optimal isn’t possible because we must look at every character.

**Q3:** *How would you handle case‑insensitivity?*  
**A:** Normalize both strings (`toLowerCase()` in Java, `tolower` in C++) before processing, or adjust the counting index to be case‑agnostic.

**Q4:** *What if the strings are streamed and you cannot store them entirely?*  
**A:** Maintain a running count array while reading the first stream, then decrement while reading the second. At the end, verify all counts are zero – still O(1) space.

---
## Summary
- **Brute‑Force:** O(n²) time, simple, good for initial thought.
- **Sorting:** O(n log n) time, leverages library, still easy to code.
- **Counting:** O(n) time, O(1) space, the optimal solution for fixed‑alphabet problems.

Use the progression to showcase problem‑solving depth and adaptability during the interview.
