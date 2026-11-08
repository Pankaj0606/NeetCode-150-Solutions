# Valid Binary Search Tree (LeetCode 98)

## Problem Statement & Core Challenges
Given the `root` of a binary tree, determine if it is a **valid binary search tree (BST)**.
A BST satisfies:
- The left subtree of a node contains only nodes with keys **strictly less** than the node's key.
- The right subtree of a node contains only nodes with keys **strictly greater** than the node's key.
- Both left and right subtrees must also be binary search trees.

The main challenges are:
1. **Recursive property** – each node must respect *global* min/max constraints, not just its immediate children.
2. **Edge cases** – duplicate values, extreme integer limits, and deep unbalanced trees.
3. **Choosing the right trade‑off** between simplicity, time, and space.

---

## Approaches
### 1️⃣ Brute‑Force (O(N²) time, O(H) space)
For every node we compute the **maximum** value in its left subtree and the **minimum** value in its right subtree and compare them to the node's value. Repeating this for each node leads to quadratic time in the worst case (e.g., a degenerate linked‑list tree).

**Pros**: Very intuitive, demonstrates the BST definition directly.
**Cons**: Inefficient for large trees.

### 2️⃣ In‑order Traversal with Array (O(N) time, O(N) space)
An in‑order traversal of a BST yields a **strictly increasing** sequence. We collect node values into a vector/array and then verify that each element is greater than the previous one.

**Pros**: Linear time, easy to explain.
**Cons**: Requires O(N) extra space for the collected values.

### 3️⃣ In‑order Traversal with Prev Variable (Optimal – O(N) time, O(H) space)
We perform an in‑order traversal while keeping track of the **previously visited node value**. If at any point the current node's value is **not greater** than `prev`, the tree is invalid. This eliminates the auxiliary array, using only the recursion stack (height `H`).

**Pros**: Linear time, only O(H) auxiliary space, works for the full integer range.
**Cons**: Slightly more bookkeeping during the interview, but still straightforward.

---

## Transition Narrative (Brute → Optimal)
1. **Start with the definition** – “left < node < right”.
2. **Realise the naive check** (max/min per subtree) is costly because we recompute sub‑tree extremes repeatedly.
3. **Observe the in‑order property** – a BST’s in‑order traversal is sorted. This gives us a linear‑time solution with extra storage.
4. **Optimize further** – we don’t need the whole list; we only need the last visited value. By threading a `prev` variable through the recursion we achieve O(1) extra space (aside from recursion stack).
5. **Conclude** – the final solution is both optimal in time and space while staying conceptually simple.

---

## Edge Cases Interviewers Love
| Scenario | Why it matters |
|----------|----------------|
| Single node | Trivial but must return `true`.
| Duplicate values | BST requires **strict** inequality; duplicates should invalidate the tree.
| Extreme INT_MIN / INT_MAX | Must use `long long`/`null` sentinel for previous value to avoid overflow.
| Deep left‑skewed or right‑skewed tree | Tests recursion depth and O(H) space handling.
| Null children only on one side | Confirms the algorithm doesn’t assume both children exist.

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this iteratively?*  
**A:** Yes. Use an explicit stack to perform in‑order traversal and keep a `prev` variable. The logic mirrors the recursive optimal solution.

**Q2:** *What if the tree is not a binary tree but a general graph?*  
**A:** The problem definition assumes a binary tree. If cycles existed, we’d need a visited set to avoid infinite loops, but that’s outside the scope of a BST validation.

**Q3:** *How would you modify the solution to allow duplicates on the **right** subtree only?*  
**A:** Change the comparison for the right side to `>=` instead of `>`. In the optimal approach, adjust the `prev` check to `current.val < prev` for left‑only strictness.

**Q4:** *What is the time complexity if the tree is balanced vs. completely unbalanced?*  
**A:** All three approaches are **O(N)** for the linear solutions regardless of shape. The brute‑force remains O(N²) in the worst (unbalanced) case because each node may scan a linear‑size subtree.

---

## Summary
- **Brute‑Force:** Direct max/min checks → O(N²).
- **In‑order + Array:** Linear time, O(N) extra space.
- **In‑order + Prev:** Linear time, O(H) space (optimal).
- Master the transition story and edge‑case handling to impress interviewers.
