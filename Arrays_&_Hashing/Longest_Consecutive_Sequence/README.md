# Longest Consecutive Sequence

## Problem Statement
Given an unsorted array of integers `nums`, return the length of the longest **consecutive** elements sequence.

You must write an algorithm that runs in **O(n)** time.

### Example
```text
Input:  nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive sequence is [1,2,3,4]. Its length is 4.
```

### Constraints
- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---

## Core Challenges
1. **Unordered input** – the array is not sorted, so a naïve scan cannot detect gaps.
2. **Time requirement** – the interview expects an O(n) solution, which forces you to think beyond sorting.
3. **Handling duplicates** – duplicates must not break the length calculation.
4. **Edge cases** – empty array, single element, all elements identical, large negative/positive values.

---

## Approaches
### 1️⃣ Brute‑Force (O(n²) time, O(1) extra space)
For every element `x` in the array, try to build the consecutive sequence starting from `x` by repeatedly checking if `x+1`, `x+2`, … exist in the array (linear scan). The longest length found is the answer.

**Why it works:** It explores every possible start point.

**Drawbacks:** The inner scan is O(n) and is executed for each of the `n` elements → O(n²).

### 2️⃣ Better – Sort & Scan (O(n log n) time, O(1) extra space)
1. Sort the array.
2. Walk through the sorted list, counting the length of each run of consecutive numbers (skip duplicates).
3. Keep the maximum run length.

**Why it works:** After sorting, consecutive numbers become adjacent, so a single linear pass suffices.

**Complexity:** Sorting dominates → O(n log n) time, O(1) additional space (in‑place sort).

### 3️⃣ Optimal – HashSet with Start‑Detection (O(n) time, O(n) space)
1. Insert all numbers into an `unordered_set` / `HashSet`.
2. For each number `x`, only start a new sequence if `x‑1` is **not** in the set (i.e., `x` is the beginning of a run).
3. From such a start, keep incrementing `x+1`, `x+2`, … while the set contains the value, counting the length.
4. Track the maximum length.

**Why it works:** Each element is visited at most twice – once when checking if it can be a start, and once while walking its run. Hence linear overall.

**Complexity:** O(n) time, O(n) extra space for the hash set.

---

## Transition Narrative (Interview Tips)
1. **Start with the obvious:** Mention the O(n²) brute‑force (nested loops or “for each element, scan forward”). Show you understand the baseline.
2. **Identify the bottleneck:** Sorting reduces the problem to a linear scan, improving to O(n log n). Explain why sorting is a natural first optimization.
3. **Reach for O(n):** Point out that the problem only asks for *existence* of consecutive numbers, not their order. A hash set gives O(1) look‑ups, enabling the start‑detection trick.
4. **Explain correctness:** Emphasize that we only start counting from the smallest element of a run, guaranteeing each run is processed exactly once.
5. **Discuss trade‑offs:** Mention the extra O(n) space and why it’s acceptable given the constraints.

---

## Edge Cases Interviewers Love
| Case | Reason |
|------|--------|
| `[]` (empty) | Should return `0`.
| `[1]` | Single element → answer `1`.
| All duplicates, e.g., `[2,2,2]` | Duplicates must be ignored; answer `1`.
| Large negative numbers, e.g., `[-3,-2,-1,0,1]` | Verify handling of negative values.
| Non‑consecutive large gaps, e.g., `[0, 1000000]` | Ensure algorithm doesn’t overflow when doing `x+1`.
| Already sorted vs. reverse sorted | Both should give same result.

---

## Mock Interview Follow‑up Q&A
**Q1.** *Can we solve the problem without extra space?*  
**A:** The O(n log n) sorting solution uses only O(1) extra space (in‑place sort). However, the true O(n) time bound requires a hash set, which incurs O(n) auxiliary space.

**Q2.** *What if the input size is 10⁷ and memory is tight?*  
**A:** We could fall back to the sort‑and‑scan method, which trades a modest O(n log n) runtime for O(1) extra memory. Another option is to use a bitset if the range of numbers is limited.

**Q3.** *How would you adapt the solution for a streaming input where numbers arrive one‑by‑one?*  
**A:** Maintain a disjoint‑set (union‑find) structure where each number is a node; when a new number arrives, union it with `num‑1` and `num+1` if they already exist. Keep track of the size of each component to report the longest run in near‑O(1) amortized time.

**Q4.** *Can we parallelize the optimal solution?*  
**A:** The hash‑set construction can be parallelized, but the start‑detection step requires global knowledge of the set. A possible approach is to partition the number space, compute local runs, then merge overlapping runs across partitions.

---

**Happy coding!**
