# Median of Two Sorted Arrays

## Problem Statement
Given two **sorted** integer arrays `nums1` and `nums2` of sizes `m` and `n` respectively, return the **median** of the combined sorted array. The overall run‑time complexity should be better than `O((m+n) log(m+n))`.

### Core Challenges
1. **Two‑array merging** without actually concatenating the whole arrays.
2. **Finding the middle element(s)** when the total length is even vs. odd.
3. **Designing an algorithm** that meets the strict `O(log(min(m, n)))` time bound required by the optimal solution.
4. Handling edge cases such as empty arrays, arrays of very different lengths, and duplicate values.

---

## Approaches
### 1️⃣ Brute‑Force (Merge‑All)
- **Idea**: Merge the two arrays into a new sorted vector, then compute the median directly.
- **Complexity**: `Time → O(m + n)`, `Space → O(m + n)`.
- **When to use**: Quick prototype, easy to explain, but not interview‑ready for the optimal constraints.

### 2️⃣ Better (Two‑Pointer Merge‑Until‑Median)
- **Idea**: Use two pointers to walk through both arrays **only up to the median index**. No extra storage is needed; we keep track of the last two visited numbers to compute the median.
- **Complexity**: `Time → O(m + n)`, `Space → O(1)`.
- **When to use**: Shows you can improve space usage and think about stopping early, a natural next step after the brute force.

### 3️⃣ Optimal (Binary‑Search Partition)
- **Idea**: Partition the two arrays such that the left side contains exactly half of the total elements and every element on the left is ≤ every element on the right. This can be found with a binary search on the smaller array.
- **Complexity**: `Time → O(log(min(m, n)))`, `Space → O(1)`.
- **When to use**: The gold‑standard solution expected by interviewers. Demonstrates mastery of binary search on answer space and careful handling of edge conditions.

---

## Transition Narrative (Interview Flow)
1. **Start with the brute‑force merge** – it’s the most straightforward and proves you understand the problem.
2. **Identify its drawbacks** – extra `O(m+n)` space and unnecessary work after the median is found.
3. **Propose the two‑pointer early‑stop version** – reduces space to `O(1)` and shows you can optimise by stopping early.
4. **Lead into the binary‑search partition** – explain that we can do even better by *not* scanning the whole arrays. Highlight the invariant that the left partition must contain the correct number of elements and be ≤ the right partition, then describe the binary search on the smaller array.
5. **Discuss edge handling** – empty arrays, partitions at the boundaries, and integer overflow when computing mid.

---

## Edge Cases Interviewers Love
| Case | Why it’s tricky |
|------|-----------------|
| One array empty | Must return median of the non‑empty array directly. |
| Very different lengths (e.g., `m = 1, n = 10⁵`) | Binary‑search must be performed on the **smaller** array to keep `log(min)` bound. |
| Both arrays contain the same repeated value | Partition logic must correctly handle `≤` vs `<`. |
| Total length is even vs. odd | Need to average two middle numbers for even length. |
| Integer overflow when computing `mid = (low + high) / 2` | Use `mid = low + (high - low) / 2`. |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this problem in `O(log(m+n))` instead of `O(log(min(m,n)))`?*  
**A:** Yes, by performing binary search on the combined length, but the classic optimal solution already achieves `O(log(min(m,n)))`, which is tighter because `min(m,n) ≤ m+n`. The partition method naturally works on the smaller array, guaranteeing the lower bound.

**Q2:** *What if the arrays are not sorted?*  
**A:** The problem definition assumes sorted input. If they were unsorted, we would need to sort them first (`O(m log m + n log n)`) before applying any of the above approaches.

**Q3:** *How would you extend the solution to find the k‑th smallest element instead of the median?*  
**A:** The binary‑search partition can be generalized: we look for a partition where the left side has `k` elements. The same invariant (`maxLeft ≤ minRight`) holds, and the algorithm runs in `O(log(min(m,n)))`.

**Q4:** *Can we implement the optimal solution iteratively without recursion?*  
**A:** Absolutely. The standard implementation uses a `while (low <= high)` loop, which is already iterative. Recursion isn’t needed.

---

## Summary
- **Brute‑force**: simple merge, `O(m+n)` time & space.
- **Two‑pointer early stop**: same time, `O(1)` space.
- **Binary‑search partition**: `O(log(min(m,n)))` time, `O(1)` space – the optimal interview answer.

Use the progression above to demonstrate problem‑solving depth and to guide the conversation toward the optimal solution.

---

**Happy coding!**
