# Subsets II – Interview Guide

## Problem Statement
Given an integer array `nums` that may contain duplicate elements, return **all possible subsets** (the power set). The solution set must **not contain duplicate subsets**. You can return the solution in any order.

**Example**
```
Input: nums = [1,2,2]
Output: [
  [],
  [1],
  [2],
  [1,2],
  [2,2],
  [1,2,2]
]
```

## Core Challenges
1. **Handling Duplicates** – Naïve subset generation will produce duplicate subsets when the input contains repeated numbers.
2. **Ensuring Uniqueness Efficiently** – We need a strategy that avoids generating the same subset more than once, or that can deduplicate cheaply.
3. **Balancing Time & Space** – Brute‑force approaches are easy to explain but blow up exponentially; interviewers love to see you reason about trade‑offs.

---

## Approaches
### 1️⃣ Brute‑Force (Bitmask + Global Deduplication)
*Generate every possible subset using a bitmask (2^n possibilities) and store a canonical representation (sorted list turned into a string) in a hash set to filter duplicates.*

**Complexities**
- **Time:** O(2^n * n log n) – we iterate over all masks, build each subset (O(n)), sort it (O(k log k) ≤ O(n log n)), and hash it.
- **Space:** O(2^n * n) for the result + O(2^n) for the hash set.

**When to use in an interview**
- First idea to show you understand the power‑set size.
- Good for a quick prototype when n ≤ 15.

---

### 2️⃣ Better / Intermediate Optimization (Backtracking + Global Set)
*Sort the input, then backtrack to generate subsets. After each recursive call we insert the current subset into a global `Set` (stringified) to guarantee uniqueness.*

**Complexities**
- **Time:** O(2^n * n) – we still explore the full recursion tree, but we avoid the per‑mask sorting step.
- **Space:** O(2^n * n) for results + O(2^n) for the set.

**Why it’s better**
- No explicit sorting of each subset; we rely on the original sorted order.
- Still uses a set, so we pay the overhead of hashing each subset.

---

### 3️⃣ Optimal Approach (Backtracking with Duplicate Skipping)
*Sort the array first. While recursing, **skip over consecutive equal numbers** when they are at the same recursion depth. This guarantees that each unique subset is generated exactly once, eliminating the need for a global deduplication structure.*

**Algorithm Sketch**
```text
backtrack(start, path):
    add copy of path to answer
    for i from start to n-1:
        if i > start && nums[i] == nums[i-1]: continue   // skip duplicate
        path.add(nums[i])
        backtrack(i+1, path)
        path.removeLast()
```

**Complexities**
- **Time:** O(2^n) – each unique subset is visited once; the inner loop runs at most n times per recursion level.
- **Space:** O(2^n * n) for the answer + O(n) recursion stack.

**Why interviewers love this**
- Demonstrates mastery of backtracking and duplicate‑handling patterns.
- Shows you can turn a “filter‑after‑generation” solution into a “generate‑only‑once” solution.

---

## Transition Narrative (Brute → Optimal)
1. **Start with the power‑set definition** – “for each element decide take / not take”.
2. **Realise duplicates break the naïve 2^n enumeration** – two different decision sequences can lead to the same subset.
3. **Introduce a global deduplication container** – easy but adds extra O(2^n) memory and hashing cost.
4. **Observe that duplicates are adjacent after sorting** – we can *prevent* the duplicate decision paths by skipping a number if it is the same as the previous one **and** we are at the same recursion depth.
5. **Result:** a clean backtrack that never creates a duplicate subset → optimal.

---

## Edge Cases Interviewers Love
| Input | Reason it’s Tricky |
|-------|--------------------|
| `[]` | Empty array – should return `[[]]`.
| `[1,1,1,1]` | All elements identical – only `n+1` unique subsets.
| `[-1,2,-1,2]` | Negative numbers and duplicates – sorting must handle sign correctly.
| Large `n` (e.g., 20) with many duplicates | Tests whether the candidate’s solution avoids exponential blow‑up due to duplicate pruning.

---

## Mock Interview Follow‑up Q&A
1. **Q:** *Can we solve this problem iteratively?*  
   **A:** Yes. Start with `[[]]` and for each number, add it to all existing subsets. To avoid duplicates, when the current number equals the previous one, only extend the subsets generated in the **previous iteration** (i.e., those that included the previous duplicate). This mirrors the backtracking skip‑duplicate logic.
2. **Q:** *What is the impact of using a `HashSet` of `List<Integer>` instead of a `String` key?*  
   **A:** Java’s `HashSet` can store lists directly because `List` implements `equals`/`hashCode` based on element order. It works, but converting to a string is often faster and avoids the overhead of creating many small `ArrayList` objects for the hash key.
3. **Q:** *How would you modify the optimal solution to return subsets in lexicographic order?*  
   **A:** Since we sort the input and always explore the “take” branch before the “skip” branch, the generated list is already lexicographically sorted. If a different order is required, we can simply sort the final `answer` vector using a custom comparator.
4. **Q:** *If the input size were 30, would the optimal solution still be feasible?*  
   **A:** The number of **unique** subsets is at most 2^n, which for n=30 is ~1 billion – too large for any solution. In practice, the presence of many duplicates reduces the count dramatically, but we would still hit memory limits. The interview discussion should pivot to “the problem is exponential by nature; we can only hope duplicates shrink the search space.”

---

## TL;DR
* Brute‑force: bitmask + global set – easy but wasteful.
* Better: backtrack + global set – removes per‑subset sorting.
* Optimal: sorted backtrack with **skip‑duplicate** rule – O(2^n) time, O(n) extra space, no post‑processing.

Use the optimal version in production; discuss the other two to show your thought process.
