# Search in Rotated Sorted Array

## Problem Statement
You are given an integer array `nums` sorted in ascending order, which has been rotated at an unknown pivot index `k` (`0 <= k < nums.length`). For example, `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]` after rotation. All values are **unique**. Given `target`, return its index if it exists in `nums`, otherwise return `-1`.

### Constraints
- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- All values of `nums` are unique.
- `-10^4 <= target <= 10^4`

## Core Challenges
1. The array is not fully sorted – a simple binary search fails.
2. We must identify which half of the current search space is properly sorted.
3. Edge cases around the rotation point (pivot) and single‑element arrays.

## Approaches

### 1️⃣ Brute‑Force (O(n) time, O(1) space)
Linear scan of the array.

### 2️⃣ Two‑Phase Binary Search (O(log n) time, O(1) space)
* **Phase 1 – Find Pivot**: The smallest element’s index is the rotation point.
* **Phase 2 – Standard Binary Search** on the appropriate half determined by the pivot.

### 3️⃣ One‑Pass Modified Binary Search (Optimal, O(log n) time, O(1) space)
During each iteration we decide which side is sorted and whether `target` lies in that side, discarding the other half immediately.

## Complexity Summary

| Approach | Time | Space |
|----------|------|-------|
| Brute‑Force | O(n) | O(1) |
| Two‑Phase Binary Search | O(log n) | O(1) |
| One‑Pass Modified Binary Search | O(log n) | O(1) |

## Interview Narrative: From Brute‑Force to Optimal
1. **Start with the obvious** – a linear scan. Shows you understand the problem.
2. **Ask about the sorted property** – “Can we exploit the fact that each half is sorted after rotation?” This leads to the pivot‑finding idea.
3. **Introduce the two‑phase solution** – find pivot, then binary search. Explain why it’s O(log n) and discuss its extra code path.
4. **Push further** – “Can we do it in a single pass without an explicit pivot?” Lead into the optimal approach, demonstrating deeper insight.

## Edge Cases Interviewers Love
- No rotation (`k = 0`): e.g., `[1,2,3,4,5]`.
- Rotation at the last element (`k = n‑1`): e.g., `[2,3,4,5,1]`.
- Single‑element array.
- Target is the pivot element.
- Target not present.

## Mock Interview Follow‑up Q&A

**Q1:** *Why can’t we just apply a normal binary search?*  
**A:** Because the global order is broken at the pivot; one half of the array is still sorted, which we must detect each iteration.

**Q2:** *How do we find the pivot in O(log n)?*  
**A:** Compare `nums[mid]` with `nums[right]`. If `mid` element is greater, the pivot lies to the right; otherwise it’s on the left or at `mid`.

**Q3:** *What if the array contains duplicates?*  
**A:** The classic O(log n) solution degrades to O(n) in the worst case because the sorted‑half check (`nums[left] <= nums[mid]`) may be inconclusive. Handling duplicates requires additional logic.

**Q4:** *Can we adapt this to “search in a rotated sorted array that may contain duplicates”?*  
**A:** Yes, by shrinking the ambiguous boundaries when `nums[left] == nums[mid] == nums[right]` (increment `left` and decrement `right`) and then proceeding with the modified binary search.

---

Feel free to copy the ready‑to‑submit implementations below for both C++ and Java.
