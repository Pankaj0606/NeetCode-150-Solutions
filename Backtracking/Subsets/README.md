# Subsets Problem (LeetCode 78)

## Problem Statement
Given an integer array `nums` of **unique** elements, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.

### Core Challenges
- Enumerating **2^n** possible subsets.
- Managing recursion/iteration without missing or duplicating subsets.
- Keeping the solution clean and interview‑friendly.

## Approaches

### 1. Brute‑Force (Backtracking – Exponential)
We recursively decide for each element whether to **include** or **exclude** it.
- **Time:** O(2^n * n) – each subset is built in O(n).
- **Space:** O(2^n * n) for the output + O(n) recursion stack.

### 2. Better (Iterative Building)
Start with `[[]]`. For each number, duplicate existing subsets and append the current number.
- **Time:** O(2^n * n) – same asymptotic work but no recursion overhead.
- **Space:** O(2^n * n) for the result; auxiliary space O(1).

### 3. Optimal (Bit‑mask Enumeration)
Treat each subset as an `n`‑bit mask where bit *i* tells if `nums[i]` is present.
- **Time:** O(2^n * n) – we still have to read each bit, which is optimal.
- **Space:** O(2^n * n) for the result; only O(1) extra variables.

## Interview Narrative: From Brute‑Force to Optimal
1. **Start with recursion** – easy to explain, shows you understand backtracking.
2. **Ask about recursion cost** – interviewers often look for iterative alternatives.
3. **Introduce iterative building** – reduces call‑stack usage and is still simple.
4. **Push further** – mention that the problem is essentially generating all bit‑masks, leading to the bit‑mask solution which is the most compact and avoids extra containers.

## Edge Cases Interviewers Love
- Empty input `[]` → should return `[[]]`.
- Single element `[x]` → `[[], [x]]`.
- Larger `n` (e.g., 20) to test exponential blow‑up handling.
- Verify that the algorithm does **not** modify the input array.

## Mock Interview Follow‑up Q&A

**Q1:** *Can we generate subsets in lexicographic order?*  
**A:** Yes, by iterating masks from `0` to `2^n‑1` the subsets appear in increasing binary order, which corresponds to lexicographic order when the input is sorted.

**Q2:** *What if the input contains duplicates?*  
**A:** The classic “subsets with duplicates” problem requires sorting first and skipping over equal elements during backtracking. That’s a slight variation (LeetCode 90).

**Q3:** *How would you reduce memory usage?*  
**A:** Generate subsets on‑the‑fly using a generator/yield (Python) or by processing each mask without storing all subsets at once, useful when only counting subsets.

**Q4:** *Is there a way to parallelise the generation?*  
**A:** Yes, each mask is independent, so the outer loop can be split across threads or distributed systems.

---

Feel free to copy the ready‑to‑submit code snippets below for C++ and Java.
