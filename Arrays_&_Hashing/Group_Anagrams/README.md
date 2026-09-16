# Group Anagrams

## Problem Statement
Given an array of strings `strs`, group the **anagrams** together.  An *anagram* is a word formed by rearranging the letters of another, using all original letters exactly once.

**Example**
```text
Input: ["eat","tea","tan","ate","nat","bat"]
Output: [["eat","tea","ate"],["tan","nat"],["bat"]]
```

The order of the groups or the order of strings within a group does **not** matter.

## Core Challenges
1. **Detecting anagrams efficiently** – naive pairwise comparison is costly.
2. **Choosing a stable key** for grouping (sorted string, frequency signature, etc.).
3. **Handling edge‑cases** – empty strings, single‑character strings, large input size, Unicode (we assume lowercase English letters as per LeetCode).

---

## Approaches
### 1️⃣ Brute‑Force (O(N²·K))
*For each string, compare it with every other string using a linear‑time anagram check (character count).*
- **Time:** `O(N²·K)` where `N` = number of strings, `K` = max length.
- **Space:** `O(N)` for the result + `O(K)` auxiliary for the count array during comparison.
- **When to use:** Demonstrates baseline thinking; interviewers may ask you to improve it.

### 2️⃣ Better / Intermediate (O(N·K·logK))
*Sort each string; the sorted version becomes a canonical key. Use a hash map to collect groups.*
- **Time:** Sorting each string costs `O(K·logK)`, total `O(N·K·logK)`.
- **Space:** `O(N·K)` for storing the keys (sorted strings) plus result.
- **Why it’s better:** Reduces pairwise checks to a single hashmap lookup.

### 3️⃣ Optimal (O(N·K))
*Create a 26‑length frequency signature for each string (e.g., "#1#0#2…"). Use this signature as the hashmap key.*
- **Time:** Building the frequency array is `O(K)` per string → `O(N·K)` overall.
- **Space:** `O(N·K)` for the signatures (each signature is a small constant‑size string) + result.
- **Best for:** Large `N` and `K`; avoids the `logK` factor of sorting.

---

## Interview Narrative – From Brute‑Force to Optimal
1. **Start with the obvious:** “I can compare every pair and group when they match.” Write the `isAnagram` helper using a 26‑size count array.
2. **Identify the bottleneck:** Pairwise comparison is `O(N²)`. Ask the interviewer if we can *pre‑process* strings.
3. **Introduce a canonical representation:** Sorting each string gives a unique identifier for its anagram class. This drops the complexity to `O(N·K·logK)`.
4. **Push further:** Sorting incurs a log factor. Since we only have lowercase letters, a fixed‑size frequency vector is enough. Encode it as a string (or tuple) and use it as a hashmap key – now we have linear time.
5. **Discuss trade‑offs:** Frequency‑based keys use constant extra space per string and are faster; however, they are a bit more code‑heavy and rely on the known alphabet size.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters | Expected handling |
|-----------|----------------|-------------------|
| Empty input `[]` | Should return `[]` without errors. | Return empty vector/list. |
| Strings with length `0` ("") | Empty string is an anagram only of itself. | Group all empty strings together. |
| All strings are identical | All go into a single group. |
| Very large `N` (10⁵) with short strings | Tests time‑complexity. | Optimal O(N·K) passes. |
| Very long strings (K≈10⁴) | Tests space and sorting overhead. | Frequency‑based key avoids `logK`. |

---

## Mock Interview Follow‑up Q&A
**Q1.** *Can we solve this without extra space for the hashmap?*  
**A:** Yes – sort the original array in‑place using the canonical key, then scan once to collect contiguous groups. This uses `O(1)` extra (ignoring output). Time stays `O(N·K·logK)`.

**Q2.** *What if the strings contain Unicode characters?*  
**A:** The frequency‑array trick works only for a known small alphabet. For Unicode we fall back to sorting each string (or using a `Map<Character,Integer>` as the signature), which yields `O(N·K·logK)`.

**Q3.** *How would you parallelise the optimal solution?*  
**A:** The signature computation for each string is independent – we can map each string to its key in parallel (e.g., using `parallelStream` in Java or OpenMP in C++). The final grouping step still needs a thread‑safe map or a reduction phase.

**Q4.** *Can we improve the constant factor of the optimal solution?*  
**A:** Yes – instead of converting the count array to a string, we can use a custom struct with `operator==` and a specialized `hash` (C++) or a `int[]` wrapped in `Arrays.hashCode` (Java). This avoids string allocation.

---

## Summary
- **Brute‑Force:** Simple pairwise check – `O(N²·K)`.
- **Better:** Sort each string → hashmap – `O(N·K·logK)`.
- **Optimal:** Frequency signature → hashmap – `O(N·K)`.
- Knowing the alphabet size lets you drop the log factor and impress the interviewer.
