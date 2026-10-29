# Invert Binary Tree

## Problem Statement
Given the `root` of a binary tree, invert the tree and return its root.

Inverting a binary tree means swapping the left and right child of every node.

### Core Challenges
- Traversing every node exactly once.
- Performing the swap **in‑place** to achieve O(1) extra space (ignoring recursion stack).
- Handling deep recursion / large trees without stack overflow.

## Approaches

### 1. Brute‑Force (Clone & Invert) – O(N) Time, O(N) Space
Create a brand‑new tree while recursively copying nodes in inverted order.

**Pros**
- Leaves the original tree untouched – useful if the caller needs the original.

**Cons**
- Allocates a new node for every element → extra memory.
- Still O(N) time, but not the optimal in‑place solution.

### 2. Iterative DFS/BFS – O(N) Time, O(N) Space
Use an explicit stack (DFS) or queue (BFS) to visit nodes iteratively and swap children.

**Pros**
- No recursion → no risk of stack overflow.
- Still O(N) time.

**Cons**
- Needs an auxiliary container that can grow to O(N) in the worst case (e.g., a completely unbalanced tree).

### 3. Optimal Recursive In‑Place – O(N) Time, O(H) Space
Swap the children of the current node, then recursively invert the left and right sub‑trees.

**Pros**
- In‑place, only the recursion stack is used (height H ≤ N).
- Clean, easy to read.

**Cons**
- For a very deep tree (degenerate linked‑list shape) recursion depth may hit language limits.

## Transition from Brute‑Force to Optimal in an Interview
1. **Start with the obvious** – “I’ll copy the tree and swap while copying.”  Shows you understand traversal and correctness.
2. **Ask about constraints** – “Do we need to keep the original tree?”  If not, you can point out the extra memory.
3. **Propose in‑place recursion** – “We can swap children while we recurse, which eliminates the extra copy.”
4. **Discuss recursion depth** – “If the tree is extremely unbalanced we could switch to an iterative stack to avoid stack overflow.”

## Edge Cases Interviewers Love
| Case | Reason |
|------|--------|
| `null` root | Empty tree – should return `null`. |
| Single node | No children to swap – result is the same node. |
| Completely left‑skewed or right‑skewed tree | Tests recursion depth / iterative stack handling. |
| Large balanced tree (≈10⁵ nodes) | Checks time‑complexity and memory usage. |

## Mock Interview Follow‑up Q&A

**Q1:** *Can we invert the tree without recursion?*  
**A:** Yes, using an explicit stack (DFS) or queue (BFS). The algorithm is identical – pop a node, swap its children, push non‑null children.

**Q2:** *What is the time‑complexity of the iterative solution?*  
**A:** Each node is visited once, so O(N). The auxiliary container holds at most O(N) nodes in the worst case.

**Q3:** *How would you handle a tree that doesn’t fit in memory?*  
**A:** You would need a streaming / external‑memory approach, e.g., process sub‑trees one at a time, but that is beyond typical interview scope.

**Q4:** *If the tree is a binary search tree, does inverting it preserve the BST property?*  
**A:** No. Inverting swaps left/right children, breaking the ordering invariant.

---

Feel free to copy the ready‑to‑submit code snippets below for your preferred language.

```
