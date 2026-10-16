# Sliding Window Maximum

## Problem Statement
Given an integer array `nums` and an integer `k`, return an array of the maximum values in each sliding window of size `k`.

## Core Challenges
- Maintaining the maximum efficiently as the window slides.
- Avoiding recomputation for each window.

## Approaches

### 1. Brute Force (O(n*k))
The simplest solution is to iterate over every window and compute the maximum by scanning the `k` elements inside it. This is easy to implement but highly inefficient for large inputs.

**Time Complexity:** O(n*k)
**Space Complexity:** O(1) (ignoring the output array)

### 2. Priority Queue (O(n log k))
Use a max‑heap (priority queue) that stores pairs of `(value, index)`. For each new element, push it onto the heap. When the window slides, pop elements from the top of the heap that are no longer inside the window. The top of the heap always gives the current maximum.

**Time Complexity:** O(n log k)
**Space Complexity:** O(k)

### 3. Deque (O(n))
Maintain a double‑ended queue that stores indices of elements in decreasing order of their values. The front of the deque always holds the index of the maximum element for the current window. When the window slides, remove indices that are out of range and remove smaller elements from the back before inserting the new index.

**Time Complexity:** O(n)
**Space Complexity:** O(k)

## Transition in an Interview
1. **Start with Brute Force** – Show you understand the problem and can implement a correct solution.
2. **Discuss its limitations** – Highlight the O(n*k) time and why it fails for large `n`.
3. **Introduce the Priority Queue** – Explain the idea of keeping a heap of candidates and lazy removal of stale indices.
4. **Move to the Deque** – Show that a deque gives the same information with O(1) amortized operations, leading to O(n) time.
5. **Summarize** – Emphasize the trade‑offs and why the deque is the optimal choice.

## Edge Cases Interviewers Love to Test
- `k == 1` (each element is its own maximum).
- `k == nums.length` (the maximum of the entire array).
- All elements equal.
- Strictly increasing or decreasing arrays.
- Negative numbers and zeros.
- Very large `k` close to `n`.

## Mock Interview Follow‑up Q&A
1. **Can we solve this with a segment tree?**
   *Yes, a segment tree can answer range maximum queries in O(log n) per query, leading to O(n log n) overall. However, the deque approach is simpler and faster in practice.
2. **What if the array is dynamic (elements inserted/removed)?**
   *A balanced BST or a binary indexed tree with order statistics could handle dynamic updates, but the sliding window problem assumes a static array.
3. **How would you modify the solution for a minimum sliding window?**
   *Swap the comparison operators: keep the deque in increasing order and the front holds the minimum.
4. **Is there a way to parallelize the brute force approach?**
   *Yes, each window’s maximum can be computed independently, so you could parallelize across threads, but the overhead may outweigh benefits for typical input sizes.
