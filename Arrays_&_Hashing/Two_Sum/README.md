# Two Sum

## Problem Statement
Given an integer array `nums` and an integer `target`, return **indices** of the two numbers such that they add up to `target`. You may assume that each input would have **exactly one solution**, and you may not use the same element twice. The answer can be returned in any order.

### Core Challenges
1. **Finding a pair efficiently** – a naïve double‑loop checks every pair (O(n²)).
2. **Preserving original indices** – sorting the array loses index information, so we must keep track of positions.
3. **Handling duplicates** – the same value may appear multiple times; we must ensure we don’t pick the same element twice.
4. **Edge‑case robustness** – empty array, single element, large numbers, negative values, and integer overflow considerations.

---

## Approaches

### 1️⃣ Brute‑Force (Worst‑Case)
```cpp
// Time: O(n²) – every pair is examined
// Space: O(1)
```
```java
// Time: O(n²)
// Space: O(1)
```
We simply iterate over all possible pairs `(i, j)` with `i < j` and return the first pair whose sum equals `target`.

---

### 2️⃣ Two‑Pass Hash Table (Better / Intermediate)
```cpp
// Time: O(n) – one pass to fill the map, another to find the complement
// Space: O(n) – hash table stores each value → index
```
```java
// Time: O(n)
// Space: O(n)
```
* First pass: store each number and its index in an `unordered_map`/`HashMap`.
* Second pass: for each element `nums[i]`, compute `complement = target - nums[i]` and check if the complement exists in the map **and** its stored index is not `i`.

This approach is easy to explain and avoids the nested loop, but it still requires two traversals of the array.

---

### 3️⃣ One‑Pass Hash Table (Optimal)
```cpp
// Time: O(n) – single traversal
// Space: O(n) – hash table holds at most n entries
```
```java
// Time: O(n)
// Space: O(n)
```
While iterating through `nums`, we look for the complement **before** inserting the current element into the map. If the complement is already present, we have found the answer instantly. This yields linear time with a single pass and is the most common interview solution.

---

## Transition Narrative (Brute → Optimal)
1. **Start with brute force** – interviewers love to see you articulate the naïve solution first.
2. **Identify the bottleneck** – O(n²) is too slow for large inputs; the inner loop is the problem.
3. **Introduce extra space** – a hash table can give O(1) look‑ups for the needed complement.
4. **Refine to one pass** – realize you don’t need to store *all* elements before searching; you can check the complement on‑the‑fly, reducing the algorithm to a single traversal.
5. **Discuss trade‑offs** – constant‑time look‑ups vs. extra memory, handling collisions, and why `unordered_map`/`HashMap` is appropriate.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters | How our code handles it |
|-----------|----------------|------------------------|
| Empty array or size < 2 | No valid pair exists | Returns empty vector/array (or throws, depending on spec) |
| Duplicate numbers that form the target (e.g., `[3,3]`, target `6`) | Must not reuse the same index | Complement check ensures indices differ |
| Negative numbers and large integers | Potential overflow when computing `target - nums[i]` | Use `long long` in C++ or rely on Java's 32‑bit int overflow semantics (LeetCode guarantees safe range) |
| Multiple valid pairs | Problem guarantees exactly one solution, but code returns the first found pair, which is acceptable |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this without extra space?*  
**A:** Yes, by sorting the array and using a two‑pointer technique (O(n log n) time, O(1) extra space). However, we must keep original indices, so we would sort a vector of `(value, index)` pairs. This is a valid alternative but not as fast as the hash‑table solution.

**Q2:** *What if the array is already sorted?*  
**A:** The two‑pointer method becomes O(n) time and O(1) space, which is optimal for a sorted input.

**Q3:** *How would you adapt the solution for “return all unique pairs that sum to target”*?  
**A:** Use a set to store seen numbers and another set to store result pairs, ensuring each pair is added only once. Complexity remains O(n) time, O(n) space.

**Q4:** *What are the pitfalls of using `unordered_map` in C++?*  
**A:** Poor hash function can degrade to O(n²) in the worst case; reserve space (`reserve(nums.size())`) to avoid rehashing, and be aware of integer overflow when computing the complement.

---

## Ready‑to‑Submit Implementations
Below are the three approaches for both C++ and Java, following the typical LeetCode class signatures.
