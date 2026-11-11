# Binary Tree Maximum Path Sum

## Problem Statement
Given a non‑empty binary tree, find the maximum sum of the values along any **path**. A path is any sequence of nodes from some starting node to any node in the tree along the parent‑child connections. The path **does not** need to go through the root, and it can start and end at any nodes. Each node can appear at most once in the path.

### Input / Output
```text
Input:  root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 → 1 → 3.
```

## Core Challenges
1. **Path direction** – the optimal path may bend at any node (i.e., go left then up then right).  
2. **Negative values** – a subtree can reduce the total sum, so we must be able to discard negative contributions.  
3. **Global optimum vs. local contribution** – while traversing we need the best *downward* gain to propagate upward, **and** we must keep a global maximum that may use both children of a node.

## Approaches
### 1️⃣ Brute‑Force (O(N²) time, O(H) space)
For every node we treat it as the highest point of the path and compute the best downward sum from its left and right sub‑trees **from scratch**.
* `maxDown(node)` – recursive helper that returns the maximum sum from `node` down to any descendant (ignores negative branches).
* `dfsAll(node)` – visits every node, calls `maxDown` on its children, updates the answer, then recurses left/right.
Because `maxDown` is recomputed for each node, the overall complexity degrades to O(N²) on a skewed tree.

### 2️⃣ Better / Intermediate (O(N) time, O(H) space)
Use a **single post‑order traversal** that returns two pieces of information:
* **maxGain** – the maximum sum from the current node down to one of its children (or 0 if both are negative). This value is returned to the parent.
* **globalMax** – updated at each node with `node.val + leftGain + rightGain`, representing the best path that *passes through* the node.
Only one DFS pass is needed, giving linear time.

### 3️⃣ Optimal (O(N) time, O(H) space, iterative) 
The recursive solution is optimal, but deep trees can cause a stack overflow. The iterative version mimics the post‑order traversal using an explicit stack and a hash‑map that stores the computed `maxGain` for each visited node. It retains the O(N) time guarantee while being safe for very deep trees.

## Complexity Summary
| Approach | Time | Extra Space |
|----------|------|-------------|
| Brute‑Force | O(N²) (worst case) | O(H) recursion stack |
| Better / Intermediate | O(N) | O(H) recursion stack |
| Optimal (iterative) | O(N) | O(H) explicit stack + O(N) map |

## Explaining the Transition in an Interview
1. **Start with the definition** – “We need the maximum sum of any path, which may bend at a node.”
2. **Brute‑Force intuition** – “If we pick every node as the bend point and compute the best left/right contributions each time, we get a correct but costly solution.”
3. **Identify the repeated work** – the downward gain for a subtree is computed many times.
4. **Introduce DP / post‑order** – “We can compute the best downward gain once per node and reuse it for its parent.”
5. **Show the one‑pass recursion** – update a global answer while returning the upward gain.
6. **Edge‑case safety** – discuss negative values and why we `max(0, gain)`.
7. **Iterative refinement** – “If recursion depth is a concern, we can replace recursion with an explicit stack, preserving the same logic.”

## Edge Cases Interviewers Love
| Edge case | Why it matters |
|-----------|----------------|
| All nodes negative | The answer is the *largest* (least negative) single node, not 0. |
| Single node tree | Base case – should return that node’s value. |
| Skewed tree (linked‑list shape) | Tests O(N²) vs O(N) behavior and recursion depth handling. |
| Large values causing overflow | Use `long long`/`int` limits; LeetCode guarantees 32‑bit fits, but mention overflow guard. |

## Mock Interview Follow‑up Q&As
**Q1:** *Why do we use `max(0, leftGain)` instead of just `leftGain`?*  
**A:** A negative contribution would decrease the path sum. By clamping to 0 we effectively “skip” that subtree, which is allowed because a path can end at the current node.

**Q2:** *Can the optimal path be completely inside the left subtree?*  
**A:** Yes. Our global `ans` is updated at every node, so the best path that lives entirely in a subtree is captured when that subtree’s root is processed.

**Q3:** *How would you modify the solution to also return the actual nodes of the maximum path?*  
**A:** Keep parent pointers or store the start/end nodes when `ans` is updated. After the traversal, reconstruct the path by walking up from both ends to the LCA.

**Q4:** *What if the tree is not binary but an N‑ary tree?*  
**A:** The same idea extends: for each node keep the two largest positive gains among its children, combine them with the node’s value for the global answer, and return the largest gain upward.

---
*Prepared for a FAANG interview – clear explanation, multiple solution tiers, and interview‑ready discussion points.*
