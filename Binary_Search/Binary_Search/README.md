# Binary Search

## Problem Statement
Given a **sorted** array of distinct integers `nums` and an integer `target`, return the index of `target` if it is present in the array. If `target` is not present, return `-1`.

**Constraints** (as per the original LeetCode problem):
- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i], target <= 10^4`
- `nums` is sorted in **strictly increasing** order.

The classic interview twist is to discuss **different levels of optimization** and to reason about edge‑cases such as empty arrays, single‑element arrays, and integer overflow when computing the middle index.

---

## Approaches Overview
| Approach | Idea | Time Complexity | Space Complexity |
|----------|------|-----------------|------------------|
| **Brute Force** | Scan the array linearly until you find `target`. | `O(n)` | `O(1)` |
| **Better (Iterative Binary Search)** | Repeatedly halve the search interval using two pointers `lo` and `hi`. | `O(log n)` | `O(1)` |
| **Optimal (Recursive Binary Search)** | Same halving logic but expressed recursively; often considered the cleanest and most interview‑friendly. | `O(log n)` | `O(log n)` (call stack) |

---

## 1️⃣ Brute‑Force (Linear Scan)
### Walkthrough
1. Iterate over the array from left to right.
2. If `nums[i] == target`, return `i`.
3. If the loop finishes, return `-1`.

### Why it works
The array is sorted, but a linear scan does **not** need that property – it simply checks every element.

### Complexity
- **Time:** `O(n)` – each element may be visited once.
- **Space:** `O(1)` – only a few scalar variables.

---

## 2️⃣ Better – Iterative Binary Search
### Walkthrough
1. Initialise `lo = 0`, `hi = nums.size() - 1`.
2. While `lo <= hi`:
   * Compute `mid = lo + (hi - lo) / 2` (prevents overflow).
   * If `nums[mid] == target` → return `mid`.
   * If `nums[mid] < target` → search the right half (`lo = mid + 1`).
   * Else → search the left half (`hi = mid - 1`).
3. If the loop ends, `target` is absent → return `-1`.

### Complexity
- **Time:** `O(log n)` – the search space halves each iteration.
- **Space:** `O(1)` – only a handful of indices.

---

## 3️⃣ Optimal – Recursive Binary Search
### Walkthrough
The recursive version mirrors the iterative logic but delegates the halving to the call stack.
```text
binarySearch(lo, hi):
    if lo > hi: return -1
    mid = lo + (hi - lo) / 2
    if nums[mid] == target: return mid
    if nums[mid] < target: return binarySearch(mid+1, hi)
    else: return binarySearch(lo, mid-1)
```
The public method simply calls `binarySearch(0, n-1)`.

### Complexity
- **Time:** `O(log n)` – same halving property.
- **Space:** `O(log n)` – recursion depth equals the number of iterations.

---

## Transitioning in an Interview
1. **Start with the obvious** – a linear scan. It shows you understand the problem and can produce a correct solution quickly.
2. **Ask about constraints** – the array is sorted, which hints at a faster algorithm.
3. **Introduce binary search** – explain the halving idea, discuss overflow‑safe mid computation, and show the iterative version first (easier to code on a whiteboard).
4. **Refactor to recursion** – if the interview is language‑agnostic, a recursive version demonstrates clean abstraction and a deeper grasp of algorithmic thinking.
5. **Discuss trade‑offs** – iterative uses `O(1)` space, recursive uses `O(log n)` stack space; both are optimal time‑wise.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters | Expected handling |
|-----------|----------------|-------------------|
| Empty array (`[]`) | No elements to search. | Return `-1` immediately.
| Single element array | Tests off‑by‑one logic. | Works for both present and absent target.
| Target smaller than first element or larger than last element | Guarantees the algorithm will quickly eliminate the search space. | Binary search will terminate after a few iterations.
| Integer overflow when computing `mid` | `mid = (lo + hi) / 2` can overflow for large indices. | Use `mid = lo + (hi - lo) / 2`.
| Duplicate values (if the problem allowed) | Determines which index to return. | Our version assumes distinct values as per constraints.

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we use `std::binary_search` (C++) or `Arrays.binarySearch` (Java) directly?*  
**A:** Yes, they are library helpers that implement the same `O(log n)` algorithm. In an interview you should still be able to write the logic yourself, but mentioning the library shows awareness of language features.

**Q2:** *What if the array is **not** sorted?*  
**A:** Binary search would be invalid. You would need to either sort first (`O(n log n)`) and then search, or fall back to linear scan (`O(n)`). Discuss the trade‑off based on the number of queries.

**Q3:** *How would you modify binary search to find the **first** or **last** occurrence of a target in a sorted array with duplicates?*  
**A:** After finding any occurrence, continue the search on the left (for first) or right (for last) side while preserving the invariant. This is a classic “lower/upper bound” variant.

**Q4:** *Can binary search be applied to problems beyond arrays, e.g., answer‑space search?*  
**A:** Absolutely. Any monotonic predicate `P(x)` (false…true) can be binary‑searched over a numeric domain, which is a common pattern in interview problems (e.g., minimum capacity to ship packages, optimal time to finish jobs, etc.).

---

**Bottom line:** Mastering the transition from a naïve linear scan to a clean binary‑search implementation—and being able to discuss its nuances—demonstrates both problem‑solving depth and communication skill, which are exactly what interviewers look for.

---

*Happy coding!*
