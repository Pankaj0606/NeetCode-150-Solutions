# Longest Substring Without Repeating Characters

## Problem Statement
Given a string `s`, find the length of the longest substring without repeating characters.

## Core Challenges
- Detecting duplicates efficiently.
- Maintaining a window that represents the current candidate substring.
- Updating the answer while scanning the string only once.

## Approaches

### 1. Brute Force (O(n³))
Generate every possible substring, check if it has all unique characters using a `Set`. Keep the maximum length.

**Time:** O(n³) – three nested loops (start, end, and set insertion).  
**Space:** O(min(n, k)) for the temporary set, where *k* is the alphabet size.

### 2. Better – Sliding Window with `Set` (O(n))
Use two pointers `left` and `right`. Expand `right` while the character is not in the set, otherwise shrink from `left`. Each character is visited at most twice.

**Time:** O(n)  
**Space:** O(k)

### 3. Optimal – Sliding Window with `HashMap` (O(n))
Store the last index of each character. When a duplicate is found, jump `left` directly to `lastIndex + 1`. This eliminates the need to shrink one step at a time.

**Time:** O(n)  
**Space:** O(k)

## Interview Narrative
1. **Start with Brute Force** – shows you understand the problem definition.
2. **Identify Redundancy** – point out repeated scanning of the same characters.
3. **Introduce Sliding Window** – explain how a moving window avoids recomputation.
4. **Optimize with Index Map** – discuss how jumping the left pointer saves time.

## Edge Cases Interviewers Love
- Empty string `""` → answer `0`.
- All identical characters `"aaaaa"` → answer `1`.
- All unique characters `"abcdef"` → answer `len(s)`.
- String with Unicode / extended ASCII characters.
- Very long string (10⁵+ characters) to test O(n) solutions.

## Mock Interview Follow‑up Q&A

**Q1:** *Can we solve it without extra space?*  
**A:** Yes, using an array of size 128/256 for ASCII characters instead of a generic hash map/set.

**Q2:** *What if the input contains Unicode characters beyond the basic multilingual plane?*  
**A:** Use a `HashMap<Character, Integer>` (Java) or `unordered_map<char32_t, int>` (C++) which can handle any `char`/`char32_t` value.

**Q3:** *How would you modify the solution to also return the substring itself?*  
**A:** Keep track of the start index of the best window while updating the maximum length, then return `s.substr(bestStart, maxLen)`.

**Q4:** *Can you generalize this to find the longest substring with at most *k* distinct characters?*  
**A:** Yes, maintain a frequency map and ensure the map size ≤ k, sliding the left pointer when it exceeds *k*.
