# Search a 2D Matrix
## Problem Statement
Given an `m x n` integer matrix `matrix` with the following properties:
- Integers in each row are sorted in non‑decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Write an algorithm that returns `true` if `target` is in the matrix, otherwise `false`.

## Core Challenges
- Recognising that the matrix can be treated as a **sorted 1‑D array**.
- Choosing the right level of binary search to meet time‑complexity expectations.
- Handling edge cases such as empty matrix or single‑row/column matrices.

## Approaches
### 1. Brute‑Force (O(m·n) time, O(1) space)
Iterate over every element and compare with `target`.

### 2. Row‑wise Binary Search (O(m·log n) time, O(1) space)
For each row, run a binary search because each row is individually sorted.

### 3. Global Binary Search (Optimal – O(log (m·n)) time, O(1) space)
Map a virtual index `i` in `[0, m·n‑1]` to `matrix[i / n][i % n]` and binary‑search the whole matrix as if it were a flat sorted array.

## Complexity Analysis
| Approach | Time | Space |
|----------|------|-------|
| Brute‑Force | O(m·n) | O(1) |
| Row‑wise Binary Search | O(m·log n) | O(1) |
| Global Binary Search | O(log (m·n)) | O(1) |

## Interview Narrative: From Brute Force to Optimal
1. **Start with the obvious** – linear scan. Shows you understand the problem.
2. **Ask clarifying questions** – “Are rows independent?” – leads to noticing each row is sorted.
3. **Propose row‑wise binary search** – improves to `O(m·log n)`.
4. **Observe the global ordering property** – first element of a row > last of previous row, which means the whole matrix is sorted when flattened.
5. **Present the optimal solution** – binary search on the virtual 1‑D index, achieving `O(log (m·n))`.

Explain each step, discuss trade‑offs, and write clean code on the whiteboard.

## Edge Cases Interviewers Love
- Empty matrix `[]` or `[[ ]]`.
- Single row or single column.
- Target smaller than the smallest element or larger than the largest.
- Matrix with duplicate values (still works because of ordering guarantees).

## Mock Interview Follow‑up Q&A
1. **Q:** *Can we achieve `O(log m + log n)`?*  
   **A:** Yes, by first binary searching the correct row (using the first column) and then binary searching within that row. This yields `O(log m + log n)` which is asymptotically the same as `O(log (m·n))`.
2. **Q:** *What if the matrix is not globally sorted, only each row is sorted?*  
   **A:** The global binary‑search trick no longer works. The best we can do is row‑wise binary search (`O(m·log n)`) or use a “search‑space reduction” technique starting from top‑right corner (`O(m + n)`).
3. **Q:** *How would you modify the solution for a matrix stored in a read‑only memory‑mapped file?*  
   **A:** The optimal approach still works because it only reads elements by index; we just need to compute the offset without copying the matrix.
4. **Q:** *If the matrix size is huge (10⁹ elements) but fits in memory, is recursion safe for binary search?*  
   **A:** Prefer an iterative binary search to avoid stack overflow; recursion depth would be at most `log₂(10⁹) ≈ 30`, which is safe, but iterative is a good habit.
