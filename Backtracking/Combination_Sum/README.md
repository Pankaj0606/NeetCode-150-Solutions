## Problem Statement
Given an array of **distinct** integers `candidates` and an integer `target`, return **all unique** combinations of `candidates` where the chosen numbers sum to `target`.  You may use the same element of `candidates` **unlimited** times. The solution set must not contain duplicate combinations.

**Example**
```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
```

### Core Challenges
1. **Exponential Search Space** – Every element can be taken 0..⌈target/min(candidates)⌉ times.
2. **Avoid Duplicates** – Different orders of the same numbers must be considered the same combination.
3. **Pruning** – Without early termination the recursion explores many dead‑ends.

---
## Approach 1 – Brute Force (No pruning, no sorting)
We recursively try **every** candidate at **every** position.
* For each recursive call we iterate over the whole `candidates` array.
* We stop when `target == 0` (found a combination) or `target < 0` (invalid).
* Because we never sort or prune, the same combination can appear in many permutations, but the problem guarantees distinct candidates, so the result is still correct albeit very slow.

**Time Complexity**: O(k^n) where `k = candidates.size()` and `n` is the maximum length of a combination (≈ target/min).  In the worst case the algorithm explores every multiset permutation.
**Space Complexity**: O(n) recursion stack + O(number of answers * average length).

---
## Approach 2 – Better (Sort + Prune by target)
1. **Sort** `candidates`.  Sorting lets us stop the loop as soon as the current candidate exceeds the remaining `target`.
2. **Start Index** – Pass the current index to the recursive call so we never consider previous elements, guaranteeing non‑decreasing order and thus eliminating duplicate permutations.
3. **Pruning** – `if (cand[i] > target) break;` cuts off large branches early.

**Time Complexity**: Much closer to the number of valid combinations, roughly O(N · C) where `C` is the total number of valid combos.  The early break reduces the branching factor.
**Space Complexity**: Same as brute force, O(n) recursion depth plus output space.

---
## Approach 3 – Optimal (Backtracking with Sorting & Early Termination)
The “better” approach is already optimal for this problem because:
* Candidates are distinct, so a simple backtrack with a start index yields each combination exactly once.
* Sorting + `cand[i] <= target` check gives the strongest possible pruning without extra memory.
* No DP table is needed because the exponential nature is unavoidable – we must output all combos.

The implementation is a clean backtracking routine that:
* Sorts once.
* Uses a single `vector<int>`/`List<Integer>` that is mutated in‑place.
* Stops the loop as soon as the candidate exceeds the remaining target.

**Time Complexity**: O(number of valid combinations · average length).  This is optimal because any algorithm must at least touch each output element.
**Space Complexity**: O(n) auxiliary recursion stack + output.

---
## From Brute Force to Optimal – How to Explain in an Interview
1. **State the naïve recursion** – “Try every candidate at every step.” Mention exponential blow‑up.
2. **Identify duplicate work** – Without ordering we revisit the same multiset in different permutations.
3. **Introduce ordering** – Sorting and always recursing with the current index (or later) forces a canonical order, removing duplicates.
4. **Add pruning** – If the smallest remaining candidate is larger than the needed sum, we can stop exploring that branch.
5. **Result** – The final backtracking is both correct and as fast as possible given the output size.

---
## Edge Cases Interviewers Love
| Edge case | Why it matters | Expected handling |
|-----------|----------------|-------------------|
| `candidates = [1]` and large `target` (e.g., 30) | Max depth of recursion, tests stack safety | Works because we keep adding `1` until target hits 0.
| `candidates` contains a number larger than `target` | Should be ignored early | Sorting + `cand[i] > target` break skips it.
| Empty `candidates` array | No combination possible | Return empty list.
| `target = 0` | The empty combination is a valid answer only if problem definition allows; LeetCode expects `[]` (no combos). Our code returns empty list because we never hit `target==0` without picking numbers.
| Large numbers causing overflow | Use `int` is fine for LeetCode constraints; otherwise use `long long`.

---
## Mock Interview Follow‑up Q&As
**Q1:** *Can we use DP instead of backtracking?*  
**A:** Yes, a DP table that stores all combos for each sub‑target works, but it uses O(target · C) memory and is usually slower than the clean backtrack because we still have to copy vectors around. Backtracking is preferred for its simplicity and lower auxiliary space.

**Q2:** *How would you modify the solution if each candidate could be used **at most once**?*  
**A:** Change the recursive call to use `i+1` instead of `i` (move to the next index) and keep the sorting/pruning logic. This turns the problem into “Combination Sum II”.

**Q3:** *What if the input may contain duplicate numbers?*  
**A:** After sorting, skip duplicates in the loop: `if (i > start && cand[i] == cand[i-1]) continue;`. This ensures each distinct number is considered only once at a given recursion depth.

**Q4:** *Can we improve the recursion depth for very large targets?*  
**A:** Iterative stack‑based backtracking or BFS can be used, but the depth is bounded by `target / min(candidates)`. In practice recursion depth ≤ 30‑40 for typical LeetCode limits, which is safe.

---
**Bottom line:** Master the canonical backtracking pattern – sort, use a start index, prune aggressively – and you can explain the evolution from brute force to the optimal solution fluently in an interview.
