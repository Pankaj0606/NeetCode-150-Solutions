# Valid Sudoku – Interview Guide

## Problem Statement
Given a 9 × 9 Sudoku board, determine if it is **valid**. The board may be partially filled, where empty cells are denoted by `'.'`. A valid board satisfies:
1. Each row contains the digits `1-9` at most once.
2. Each column contains the digits `1-9` at most once.
3. Each of the nine 3 × 3 sub‑boxes contains the digits `1-9` at most once.

The input is a 2‑D array `board[9][9]` of characters. Return `true` if the board is valid, otherwise `false`.

---

## Core Challenges
* **Multiple constraints** – rows, columns, and sub‑boxes must be checked simultaneously.
* **Space‑time trade‑off** – a naïve solution can be written quickly but is inefficient; interviewers love to see you reason about better data structures.
* **Edge handling** – ignore `'.'` cells and ensure you don’t go out of bounds when iterating sub‑boxes.

---

## Approaches
### 1️⃣ Brute‑Force (O(N³) time, O(1) extra space)
* For each row, compare every pair of filled cells.
* Repeat for each column.
* For each 3 × 3 box, compare every pair inside the box.
* `N = 9`, so the algorithm is still fast enough, but the nested loops are a clear interview red flag.

### 2️⃣ Better / Intermediate (O(N²) time, O(N) space)
* Scan the board once.
* Maintain three arrays of `bool[9]` (or `HashSet<Character>`) for rows, columns, and boxes.
* For a digit `d` at `(r,c)`, compute the box index `b = (r/3)*3 + c/3`.
* If `d` is already seen in the corresponding row/col/box → invalid.
* Otherwise, mark it as seen.
* This reduces time to linear in the number of cells and uses only 27 × 9 ≈ 243 booleans.

### 3️⃣ Optimal (O(N²) time, O(N) space – bit‑mask version)
* Replace the three `bool[9]` arrays with three `int[9]` bit‑masks.
* Each bit `1 << (d‑1)` represents the presence of digit `d`.
* Checking/setting becomes a single bit‑wise operation, which is the fastest in practice and demonstrates mastery of low‑level optimization.

---

## Transition Narrative (Brute → Optimal)
1. **Start with the obvious** – “I’ll compare every pair in each row/col/box.”
2. **Identify the bottleneck** – the repeated scanning of the same cells leads to O(N³).
3. **Introduce a single pass** – “What if we remember what we have already seen?” → bring in hash‑sets / boolean arrays.
4. **Compress the memory** – “We only need 9 bits per row/col/box, why not store them in an `int`?” → bit‑mask solution.
5. **Explain trade‑offs** – constant‑time checks, negligible extra space, and cleaner code.

---

## Edge Cases Interviewers Love
| Situation | Why it matters | Expected handling |
|-----------|----------------|-------------------|
| All cells are `'.'` | Empty board is trivially valid | Return `true` |
| Duplicate in a row but not in column/box | Checks must be independent | Detect via row‑set/bitmask |
| Duplicate in a column only | Same as above | Detect via column structure |
| Duplicate across two different sub‑boxes | Must compute box index correctly | Use `(r/3)*3 + c/3` |
| Invalid characters (e.g., `'0'` or `'a'`) | LeetCode guarantees only `'.'` or `'1'‑'9'`, but robust code can guard | Optionally return `false` early |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we stop early once we find a violation?*  
**A:** Yes. As soon as a duplicate is detected we return `false`. This is true for all three approaches.

**Q2:** *What is the overall space complexity of the bit‑mask solution?*  
**A:** We store three arrays of 9 integers → O(9) = O(1) extra space (constant w.r.t. input size).

**Q3:** *How would you adapt the solution for a variable‑size Sudoku (e.g., 16×16)?*  
**A:** Generalize `N = sqrt(board.size())`. Use `vector<vector<bool>>` or `unordered_set` sized `N` for rows/cols/boxes. For bit‑mask, you’d need a larger integer type (e.g., `long long` or `BigInteger`).

**Q4:** *Is there any advantage to checking rows, columns, and boxes in separate passes versus a single unified pass?*  
**A:** A single pass is more cache‑friendly and avoids three full traversals, but separate passes are sometimes clearer for a beginner. In an interview, start with the clear single‑pass hash‑set solution, then discuss the bit‑mask refinement.

---

## TL;DR
* **Brute‑Force:** nested loops → O(N³).
* **Better:** one pass with three `bool[9]` arrays → O(N²) time, O(N) space.
* **Optimal:** one pass with three `int` bit‑masks → O(N²) time, O(1) space.
* Explain the evolution, discuss edge cases, and be ready to answer follow‑up design questions.
