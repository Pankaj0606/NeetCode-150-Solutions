# Maximum Depth of Binary Tree

## Problem Statement
Given the `root` of a binary tree, return *its maximum depth*.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Example**
```
Input: root = [3,9,20,null,null,15,7]
Output: 3
Explanation: The longest path is 3 → 20 → 15 (or 3 → 20 → 7).
```

## Core Challenges
1. **Tree Traversal** – You must visit every node to know the deepest leaf.
2. **Space Management** – Recursive solutions use the call‑stack; iterative solutions use an explicit data structure.
3. **Choosing the Right Strategy** – Interviewers love to see you reason about trade‑offs (DFS vs BFS, recursion vs iteration).

---

## Approaches
### 1️⃣ Brute‑Force (O(N²) time, O(H) space)
**Idea**: For each node, recompute the height of its subtree *from scratch*.
- `height(node)` walks the entire subtree to compute its height.
- `maxDepth(node)` calls `height(node)` **and** recurses on both children, causing repeated work.

**Why it’s a brute force?**
Every node’s subtree is visited many times → quadratic time on a skewed tree.

**Complexities**
- Time: **O(N²)** in the worst case (e.g., a linked‑list shaped tree).
- Space: **O(H)** recursion stack, where *H* is the height of the tree.

---
### 2️⃣ Better / Intermediate (BFS – O(N) time, O(W) space)
**Idea**: Perform a level‑order traversal using a queue. Each level we increment a counter.
- When the queue becomes empty, the counter equals the maximum depth.

**Complexities**
- Time: **O(N)** – each node is enqueued/dequeued once.
- Space: **O(W)** – *W* is the maximum width of the tree (worst‑case O(N) for a full tree).

---
### 3️⃣ Optimal (DFS – O(N) time, O(H) space)
**Idea**: Classic post‑order recursion. The depth of a node is `1 + max(depth(left), depth(right))`.
- The recursion returns the height of each subtree exactly once.

**Complexities**
- Time: **O(N)** – linear scan.
- Space: **O(H)** – recursion stack depth equals tree height (O(log N) for balanced, O(N) for skewed).

---

## Transitioning from Brute‑Force to Optimal in an Interview
1. **State the brute‑force** and explain its inefficiency (re‑computing heights).
2. **Ask a guiding question**: *"Can we avoid recomputing the height of a subtree if we already know it?"*
3. **Introduce memoisation / bottom‑up thinking** – leads directly to the DFS solution where each subtree’s height is computed once and propagated upward.
4. **Optionally discuss BFS** as an alternative that also achieves O(N) but uses a different data structure, showing breadth of knowledge.

---

## Edge Cases Interviewers Love
| Edge Case | Why It’s Tricky | Expected Result |
|-----------|----------------|-----------------|
| `root == nullptr` | Empty tree – must not crash | `0` |
| Single node tree | Depth is 1, not 0 | `1` |
| Completely skewed tree (all left or all right) | Height = N, recursion depth = N → stack overflow risk in some languages | `N` |
| Full balanced tree | Checks if you correctly count all levels | `log₂(N+1)` (rounded up) |
| Tree with `null` children interleaved | Ensures you treat `null` as depth 0 | Correct max depth |

---

## Mock Interview Follow‑up Q&A
**Q1:** *Can we solve this problem without recursion?*  
**A:** Yes. Use an iterative BFS (queue) or an explicit stack for DFS. Both achieve O(N) time.

**Q2:** *What is the space complexity of the BFS solution on a perfect binary tree of height h?*  
**A:** The maximum width is `2^{h-1}` nodes, so space is O(2^{h}) = O(N).

**Q3:** *How would you modify the algorithm to also return the deepest leaf node(s)?*  
**A:** In BFS, keep track of the last level’s nodes; in DFS, propagate the deepest leaf up alongside depth.

**Q4:** *If the tree is extremely deep (e.g., 10⁵ nodes), what would you change?*  
**A:** Prefer an iterative DFS/BFS to avoid stack overflow, or increase recursion limit / use tail‑recursion optimisation where language permits.

---

**Bottom line:** Mastering the transition from a naïve repeated‑work solution to a clean linear‑time DFS (or BFS) demonstrates both problem‑solving rigor and practical coding skill – exactly what interviewers look for.
