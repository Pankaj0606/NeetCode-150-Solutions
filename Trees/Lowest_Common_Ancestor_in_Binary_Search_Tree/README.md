# Lowest Common Ancestor in a Binary Search Tree

## Problem Statement
Given the `root` of a **Binary Search Tree (BST)** and two nodes `p` and `q` (both guaranteed to exist in the tree), return their **lowest common ancestor (LCA)**.

- The LCA of two nodes `p` and `q` is the deepest node that has both `p` and `q` as descendants (a node can be a descendant of itself).
- Because the tree is a BST, for any node `n`:
  - All nodes in `n.left` have values `< n.val`.
  - All nodes in `n.right` have values `> n.val`.

### Core Challenges
1. **Leverage BST properties** – they let us decide which side of the tree to explore without traversing the whole structure.
2. **Explain trade‑offs** – interviewers love to see you discuss time vs. space and why one approach is preferable.
3. **Edge‑case awareness** – duplicate values (not allowed in classic BST), one node being the ancestor of the other, and very skewed trees.

---

## Approaches
### 1️⃣ Brute‑Force (Path Comparison)
**Idea**: Build the root‑to‑`p` and root‑to‑`q` paths, then scan from the start until the paths diverge. The last common node is the LCA.

**Algorithm**
1. DFS/BFS to collect the path from `root` to `p` (store nodes in a vector).
2. Repeat for `q`.
3. Iterate both vectors in parallel; the last equal node is the answer.

**Complexities**
- **Time**: `O(N)` – we may visit every node while building the two paths.
- **Space**: `O(N)` – two vectors store up to the height of the tree (worst‑case `N`).

---

### 2️⃣ Better / Intermediate (Recursive BST‑Guided Search)
**Idea**: Use the BST ordering to prune sub‑trees, but implement it recursively. The recursion stops as soon as we find a split point where `p` and `q` lie on different sides (or one matches the current node).

**Algorithm**
```text
if root.val > p.val && root.val > q.val → recurse left
if root.val < p.val && root.val < q.val → recurse right
otherwise → root is LCA
```

**Complexities**
- **Time**: `O(H)` where `H` is the height (average `O(log N)`, worst `O(N)`).
- **Space**: `O(H)` recursion stack.

---

### 3️⃣ Optimal (Iterative BST‑Guided Search)
**Idea**: Same logic as the recursive version but eliminate the call stack. Iterate down the tree until the split point is found.

**Algorithm**
```text
while root != null:
    if both p and q < root → root = root.left
    else if both p and q > root → root = root.right
    else break   // split point found
return root
```

**Complexities**
- **Time**: `O(H)` – each step moves strictly downwards.
- **Space**: `O(1)` – only a few pointers.

---

## Transitioning in an Interview
1. **Start with the obvious** – mention the path‑comparison brute force. It shows you understand the definition of LCA.
2. **Ask about BST properties** – the interviewer will hint that we can do better because the tree is ordered.
3. **Move to a recursive guided search** – explain how the split point works and that we only need to follow one branch.
4. **Optimize further** – point out the recursion stack and suggest an iterative version for `O(1)` extra space.
5. **Discuss edge cases** – what if `p` is ancestor of `q`? The split point logic still returns `p` correctly.

---

## Edge Cases Interviewers Love
| Scenario | Why it matters | Expected handling |
|----------|----------------|-------------------|
| `p` is the root | LCA should be the root itself | Split point condition catches it immediately |
| `q` is a descendant of `p` | LCA is `p` | The algorithm returns the ancestor when one node matches the current root |
| Skewed tree (all left or all right) | Height = `N` → worst‑case time `O(N)` | Both recursive and iterative still work, just degrade to linear time |
| Identical values (invalid BST) | Should not happen; clarify assumptions | Mention that the problem guarantees distinct values |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this without using the BST property?*  
**A:** Yes, the generic LCA algorithm for a binary tree works (post‑order DFS returning flags). It runs in `O(N)` time and `O(H)` space, but we lose the `O(log N)` advantage of a BST.

**Q2:** *What if the tree is not a BST but still a binary tree?*  
**A:** Use the classic recursive solution: traverse left/right, return the node that is either `p`, `q`, or the LCA when both sides report a hit.

**Q3:** *How would you modify the solution to handle a **parent pointer** in each node?*  
**A:** Build the ancestor set for `p` by climbing via parent pointers, then climb from `q` until you hit a node in that set – `O(H)` time, `O(H)` space.

**Q4:** *If the tree is extremely large and stored on disk, which approach is most I/O‑friendly?*  
**A:** The iterative BST‑guided search, because it visits at most one node per level, minimizing disk reads.

---

## Summary
- **Brute force**: easy to explain, `O(N)` time & space.
- **Recursive BST‑guided**: leverages ordering, `O(H)` time, `O(H)` stack.
- **Iterative BST‑guided**: optimal `O(H)` time, `O(1)` extra space.

Pick the iterative version for production code; discuss the recursive version to show depth‑first thinking, and keep the brute‑force as a baseline.
