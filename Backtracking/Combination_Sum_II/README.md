# Combination Sum II

## Problem Statement
Given an integer array `candidates` (which may contain duplicates) and an integer `target`, return **all unique** combinations of `candidates` where the chosen numbers sum to `target`. Each number in `candidates` may be used **at most once** in the combination.

The solution set must not contain duplicate combinations.

### Example
```text
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[[1,1,6],[1,2,5],[1,7],[2,6]]
```

## Core Challenges
1. **Handling duplicates** – because the input can contain repeated numbers, naïve back‑tracking will generate duplicate subsets.
2. **Choosing each element at most once** – unlike Combination Sum I, we cannot reuse an element.
3. **Pruning** – the search space is exponential (`2^n`). Efficient pruning is required to stay within time limits.

## Approaches
### 1️⃣ Brute‑Force (Generate All Subsets)
* Generate every possible subset (2ⁿ possibilities) via recursion.
* Keep subsets whose sum equals `target`.
* Sort each valid subset and insert it into a `set` (C++) / `HashSet` (Java) to remove duplicates.

**Complexities**
- Time: O(2ⁿ * n log n) – we explore every subset and sort each valid one.
- Space: O(2ⁿ) for storing all subsets (worst case) plus recursion stack O(n).

### 2️⃣ Better – Backtracking + Post‑Deduplication
* Sort the input array first.
* Perform classic backtracking (choose / not‑choose) **without** duplicate‑skip logic.
* Store every combination that hits the target.
* After the recursion finishes, deduplicate the result using a `set` of vectors.

This reduces the constant factor because we never build the full power‑set, but we still need a deduplication pass.

**Complexities**
- Time: O(2ⁿ) in the worst case (still exponential) but usually faster than the pure power‑set because we stop early when the running sum exceeds `target`.
- Space: O(k·l) for `k` results of average length `l`, plus recursion stack O(n).

### 3️⃣ Optimal – Backtracking with Pruning & Duplicate Skipping
* Sort the array.
* During recursion, **skip** an element if it is the same as the previous one **and** the previous one was not chosen at this depth (`i > start && candidates[i] == candidates[i‑1]`).
* **Prune** the branch as soon as `candidates[i] > remainingTarget` because the array is sorted.
* Add a combination to the answer list as soon as the remaining target becomes `0`.

This approach generates each unique combination exactly once – no post‑processing needed.

**Complexities**
- Time: O(2ⁿ) in the worst case, but the pruning and duplicate‑skip dramatically cut the search space; typical runtime is near O(k·l) where `k` is the number of unique answers.
- Space: O(k·l) for the output + O(n) recursion stack.

## Interview Narrative – From Brute‑Force to Optimal
1. **Start with the obvious** – “Let’s generate every subset and filter by sum.” Explain the exponential nature and the need for deduplication.
2. **Introduce backtracking** – “We can avoid building the whole power‑set by stopping early when the partial sum exceeds the target.” Show the classic include/exclude recursion.
3. **Handle duplicates early** – “If the array is sorted, we can skip over equal numbers at the same recursion depth, guaranteeing uniqueness without a set.”
4. **Add pruning** – “Because the array is sorted, once a candidate is larger than the remaining target we can break the loop.”
5. **Result** – “We now have a clean, O(k·l) solution that the interviewer will love.”

## Edge Cases Interviewers Love
| Edge case | Why it matters | Expected handling |
|-----------|----------------|-------------------|
| Empty `candidates` | No numbers to choose from | Return empty list `[]` |
| `target` = 0 | Only the empty combination is valid, but the problem definition usually expects no empty combination; return `[]` |
| All numbers larger than `target` | No combination possible – algorithm must prune quickly |
| Many duplicates (e.g., `[1,1,1,1,1]`) | Tests duplicate‑skipping logic – should return only one combination if it sums to `target` |
| Large input size (n ≈ 30) | Forces exponential solutions to be optimized; pure power‑set will TLE |

## Mock Interview Follow‑up Q&A
**Q1:** *Can we solve this problem with DP?*  
**A:** Yes, a DP that tracks combinations for each sum works, but it requires storing sets of vectors and handling duplicates, which is memory‑heavy. Backtracking is usually preferred for interview clarity.

**Q2:** *What if each number could be used unlimited times?*  
**A:** That becomes Combination Sum I. The only change is to keep the current index (`i`) instead of `i+1` when recursing, allowing reuse.

**Q3:** *How would you modify the solution to return combinations in lexicographic order?*  
**A:** Since we sort the input and always iterate forward, the generated combinations are already lexicographically sorted. If a different order is required, we can sort the final answer list.

**Q4:** *What is the impact of using a `set` for deduplication on time complexity?*  
**A:** Inserting each combination into a `set` costs O(l log m) where `l` is combination length and `m` is the number of stored combos. This adds an extra logarithmic factor, which is why the optimal approach avoids a set entirely.

---
*Prepared for a senior‑level interview – feel free to adapt the explanations to your personal style.*
