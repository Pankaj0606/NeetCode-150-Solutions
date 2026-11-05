# Binary Tree Level Order Traversal

## Problem Statement
Given the `root` of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

**Example**
```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

## Core Challenges
1. Traversing the tree **by depth** rather than by pre‑order/in‑order/post‑order.
2. Managing the boundary between levels efficiently.
3. Handling edge cases such as an empty tree or a highly unbalanced tree.

## Approaches
### 1️⃣ Brute Force – Recursive per‑level (O(N²) time)
* Compute the height `h` of the tree.
* For each level `i` from `1` to `h`, run a DFS that collects nodes exactly at depth `i`.
* **Time:** O(N · h) → O(N²) in the worst case (skewed tree).
* **Space:** O(h) recursion stack + O(N) for output.

### 2️⃣ Better – Iterative BFS with Two Queues (O(N) time, O(N) space)
* Use two queues: `current` holds nodes of the current level, `next` gathers children for the following level.
* After draining `current`, swap the queues.
* This removes the need for a size counter but still uses extra queue storage.
* **Time:** O(N)
* **Space:** O(N) (both queues together hold at most one level of nodes).

### 3️⃣ Optimal – Single‑Queue BFS with Level Size Loop (O(N) time, O(N) space)
* Classic breadth‑first search: push the root, then repeatedly process `queue.size()` nodes – that size equals the number of nodes on the current level.
* No extra queue, only one `queue` and a temporary vector for the current level.
* **Time:** O(N)
* **Space:** O(N) (queue holds at most the widest level).

## Transition Narrative (Interview)
1. **Start with the obvious recursive solution** – many candidates think of “visit each level separately”. Explain the height‑first idea and quickly point out the O(N²) cost on a skewed tree.
2. **Introduce BFS** – ask the candidate how to visit nodes level by level without recomputing depth. The natural answer is a queue.
3. **Refine the BFS** – discuss implementation details. A candidate may propose two queues; you can then guide them to the more idiomatic single‑queue + size loop, highlighting reduced constant factors and cleaner code.
4. **Conclude with optimality** – emphasize that the final solution is both time‑optimal (visits each node once) and space‑optimal (stores only one level).

## Edge Cases Interviewers Love
| Edge case | Why it matters |
|-----------|----------------|
| `root == nullptr` | Guarantees you handle empty input without segfaults. |
| Single node tree | Checks that you still return `[[val]]` and not an empty list. |
| Completely skewed tree (all left or all right) | Turns the height‑first brute force into O(N²); tests if you understand worst‑case complexity. |
| Very wide tree (e.g., root with 10⁴ children) | Ensures you don’t exceed recursion depth and that your queue can hold many nodes. |

## Mock Interview Follow‑up Q&A
**Q1:** *Can we solve this without extra space for the output?* 
**A:** No, the output itself is O(N) because we must store every node value. Any algorithm must allocate at least that much.

**Q2:** *What if we need a zig‑zag (spiral) order instead of plain level order?* 
**A:** Use two stacks or a deque to alternate the direction of insertion while still processing level by level.

**Q3:** *How would you modify the optimal solution to return the average value of each level?* 
**A:** While building each `level` vector, also accumulate a sum and after the inner loop push `sum / level.size()` to a separate result vector.

**Q4:** *Is there a way to perform level order traversal using recursion only?* 
**A:** Yes, the brute‑force approach (height + per‑level DFS) is recursive, but it incurs O(N²) time. A more advanced recursive method uses a helper that passes the current depth and appends to a vector of vectors, achieving O(N) time, but it still uses the call stack proportional to the tree height.

---
*Prepared for a senior‑level interview – feel free to adapt the explanations to your style.*
