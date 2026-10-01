# 3Sum Problem – Interview Guide

## Problem Statement
Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, `j != k` and `nums[i] + nums[j] + nums[k] == 0`.  The solution set must not contain duplicate triplets.

## Core Challenges
* Handling duplicates efficiently.
* Reducing the naïve O(n³) enumeration to O(n²).
* Explaining the two‑pointer technique after sorting.

## Approaches

### 1. Brute Force – O(n³) time, O(1) extra space
* Triple nested loops enumerate every combination.
* Use a `set` (or sort each triplet) to avoid duplicates.

### 2. Better – O(n² log n) time, O(n) space
* Sort the array.
* For each index `i`, binary‑search for `-(nums[i] + nums[j])` for every `j > i`.
* Store results in a `set` to deduplicate.

### 3. Optimal – O(n²) time, O(1) extra space (apart from output)
* Sort the array.
* Fix the first element `i` and use two pointers `left` and `right` to find pairs that sum to `-nums[i]`.
* Skip duplicates by moving pointers past equal values.

## Complexity Summary

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n³) | O(1) (output) |
| Better | O(n² log n) | O(n) for sorting + O(k) for result |
| Optimal | O(n²) | O(1) extra (output) |

## How to Transition in an Interview
1. **Start with brute force** – show you understand the problem and can write a correct solution.
2. **Identify bottlenecks** – the triple loop is the hot spot; ask about sorting.
3. **Introduce sorting** – reduces search for the third element to binary search or two‑pointer.
4. **Explain binary search version** – still O(n² log n) but shows improvement.
5. **Move to two‑pointer** – constant‑time pair search after sorting, achieving O(n²).
6. **Discuss duplicate handling** – crucial for correctness and to keep the output unique.

## Edge Cases Interviewers Love
| Input | Reason |
|-------|--------|
| `[]` or size < 3 | No triplet possible. |
| All zeros `[0,0,0,0]` | Must return a single `[0,0,0]`. |
| No possible triplet `[-1,1,2]` | Return empty list. |
| Large range with duplicates `[-2,0,0,2,2]` | Tests duplicate skipping logic. |
| Already sorted vs unsorted | Ensure you sort inside the solution. |

## Mock Interview Follow‑up Q&A

**Q1:** *Can we solve 3Sum in O(n²) without sorting?*  
**A:** Yes, using a hash‑set for each fixed element to find the complement in O(1) average time, but handling duplicates becomes messy and overall space rises to O(n²). Sorting gives a clean O(1) extra‑space two‑pointer solution.

**Q2:** *How would you extend this to “4Sum”?*  
**A:** Generalize the pattern: sort the array and recursively fix `k‑1` numbers, then apply the two‑pointer technique for the last two. Complexity becomes O(n^{k‑1}).

**Q3:** *What if the target sum is not zero?*  
**A:** Pass the target as a parameter and look for `target - nums[i]` instead of `-nums[i]`. The rest of the algorithm stays unchanged.

**Q4:** *Why do we need to skip duplicates after moving the pointers?*  
**A:** Without skipping, the algorithm would emit the same triplet multiple times because equal values produce identical sums. Skipping guarantees each unique triplet appears once.

---

Feel free to adapt the code snippets below to your preferred language and discuss each step with the interviewer.
