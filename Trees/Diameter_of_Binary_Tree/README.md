# Diameter of Binary Tree

## Problem Statement
Given the `root` of a binary tree, return the length of the **diameter** of the tree.  
The diameter is the number of edges on the longest path between any two nodes in the tree.  
The path may or may not pass through the root.

### Core Challenges
- Understanding that the longest path can be **any** node pair, not just leaf‑to‑leaf.
- Balancing between recomputing subtree heights and keeping the solution linear.
- Communicating the intuition of “height + height = possible diameter” during an interview.

## Approaches

### 1️⃣ Brute‑Force (O(N²) time, O(N) space)
For every node we:
1. Compute the height of its left and right subtrees (`height` is a separate recursive call).
2. The diameter that passes through this node is `leftHeight + rightHeight`.
3. Recursively compute the diameter of the left and right sub‑trees and take the maximum.

**Why it’s O(N²)** – `height` is called for each node, and each `height` itself traverses the subtree again.

### 2️⃣ Better / Intermediate (O(N) time, O(N) space)
Cache the height of each subtree in a hash‑map (or unordered_map).  
Now each node’s height is computed once, but we still keep the “divide‑and‑conquer” structure of the brute‑force solution.

**Complexities**
- Time: O(N) – each node is visited a constant number of times.
- Space: O(N) – recursion stack + hash‑map for memoisation.

### 3️⃣ Optimal / One‑Pass DFS (O(N) time, O(H) space)
Perform a post‑order DFS that returns the height of the current node.
While unwinding, update a global `diameter` with `leftHeight + rightHeight`.  
Only one traversal is needed.

**Complexities**
- Time: O(N)
- Space: O(H) where H is the height of the tree (recursion stack).

## Interview Narrative – From Brute‑Force to Optimal
1. **Start with the definition** – “diameter = longest path = leftHeight + rightHeight for some node”.
2. **Write the naïve recursion** – compute height repeatedly → O(N²).  
   *Explain why it’s inefficient* (re‑visiting sub‑trees).
3. **Introduce memoisation** – store heights → O(N) but still two passes.  
   *Show the code change* (hash‑map) and discuss space trade‑off.
4. **Push for a single pass** – realize we can compute height **and** update diameter together during the same DFS.  
   *Present the optimal code* and emphasise O(N) time & O(H) space.

## Edge Cases Interviewers Love
| Edge case | Why it matters |
|-----------|----------------|
| Empty tree (`root = null`) | Diameter should be `0`. |
| Single node | No edges → diameter `0`. |
| Skewed tree (all left or all right) | Diameter equals number of nodes‑1; tests recursion depth handling. |
| Tree with multiple equal‑length longest paths | Confirms you’re taking the maximum, not the first found. |

## Mock Interview Follow‑up Q&A

**Q1:** *Can we compute the diameter without recursion?*  
**A:** Yes, using an explicit stack for iterative post‑order traversal or BFS to find the farthest node twice (tree diameter property). The iterative DFS version has the same O(N) complexity.

**Q2:** *What if the tree is extremely deep (e.g., 10⁵ nodes) – will recursion overflow?*  
**A:** In production you’d switch to an iterative DFS or increase the stack size. The algorithmic complexity stays O(N).

**Q3:** *How would you modify the solution to return the actual nodes on the longest path?*  
**A:** Keep parent pointers while traversing, or after finding the two farthest nodes (using two BFS passes) reconstruct the path by back‑tracking.

**Q4:** *Is there a difference between “number of edges” and “number of nodes” in the definition?*  
**A:** LeetCode defines diameter as number of edges, so we return `leftHeight + rightHeight` (heights are counted in edges). If nodes were required, add `+1`.

---

Feel free to copy the ready‑to‑submit code snippets below for C++ and Java.
