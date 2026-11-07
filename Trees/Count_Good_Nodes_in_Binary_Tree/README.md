# Count Good Nodes in a Binary Tree

## Problem Statement
Given the `root` of a binary tree, a node is **good** if on the path from the root to that node there are no nodes with a value greater than the node's value. In other words, a node `x` is good if `x.val >= max(root.val, …, parent_of_x.val)`. Return the number of good nodes in the tree.

### Core Challenges
1. **Path‑dependent condition** – the decision for a node depends on the maximum value seen **so far** on the root‑to‑node path.
2. **Balancing time vs. space** – a naïve solution can recompute the maximum for every node (quadratic time). The optimal solution must propagate the maximum while traversing the tree only once.
3. **Edge‑case handling** – empty tree, single node, strictly decreasing/increasing values, and deep skewed trees that can blow the recursion stack.

---

## Approaches
### 1️⃣ Brute‑Force (O(N²) time, O(H) extra space per inner call)
*For every node we recompute the maximum value on the path from the root to that node.*

**Algorithm**
1. Perform a standard DFS that visits each node `cur`.
2. For each visited node, start a **second** DFS from the root that follows the unique path to `cur` and records the maximum value on that path.
3. If `cur.val` is greater than or equal to that maximum, increment the answer.

**Complexities**
- **Time:** In a balanced tree the inner DFS visits O(depth) ≈ O(log N) nodes per outer node, giving O(N log N). In the worst case (completely skewed) depth = N, so O(N²).
- **Space:** Recursion depth of the outer DFS is O(H) and the inner DFS adds another O(H) → O(H) overall.

---

### 2️⃣ Better / Intermediate (O(N) time, O(H) space)
*Propagate the maximum value seen so far while traversing the tree once.*

**Algorithm**
- Use a pre‑order DFS (recursive or iterative).
- Pass the current maximum `maxSoFar` down the recursion.
- A node is good if `node.val >= maxSoFar`. Increment the counter and update `maxSoFar = max(maxSoFar, node.val)` for its children.

**Complexities**
- **Time:** Each node is visited exactly once → **O(N)**.
- **Space:** Recursion stack depth equals tree height → **O(H)** (O(log N) for balanced, O(N) for skewed).

---

### 3️⃣ Optimal (O(N) time, O(1) extra space) – Morris Pre‑order Traversal
The previous approach is already linear, but it uses O(H) call‑stack space. Using **Morris traversal** we can achieve **O(1)** auxiliary space while still visiting each node exactly once.

**Algorithm**
1. Initialise `cur = root` and `maxSoFar = INT_MIN`.
2. While `cur` is not `nullptr`:
   - If `cur->left` is `nullptr`:
     * Process `cur` (check good node, update `maxSoFar`).
     * Move to `cur->right`.
   - Else find the **predecessor** (right‑most node in `cur`'s left subtree).
     * If predecessor's right child is `nullptr`, create a temporary thread `predecessor->right = cur` and move `cur = cur->left`.
     * If the thread already exists, remove it, process `cur`, and move to `cur->right`.
3. The temporary threads guarantee we never use a stack.

**Complexities**
- **Time:** Each edge is visited at most twice → **O(N)**.
- **Space:** Only a few pointers and an integer → **O(1)**.
- **Note:** The tree is restored to its original shape before the algorithm finishes.

---

## Interview Narrative – From Brute‑Force to Optimal
1. **Start with the definition** – “good node = node value ≥ max on the path”. The most straightforward mental model is *"for each node, walk back to the root and compute the max"* – that’s the brute‑force.
2. **Identify the repeated work** – the max on the path to a child is just `max(parentMax, parent.val)`. This observation lets you *carry* the maximum while you go down, eliminating the inner traversal → the intermediate solution.
3. **Space pressure** – interviewers love to ask about recursion depth. Mention that the recursive solution is O(H) space and that you can convert it to an iterative stack‑based version with the same O(N) time.
4. **Push further** – if they probe for *O(1) space*, bring up Morris traversal. Explain the temporary threading trick, reassure them that the tree is restored, and discuss the trade‑off (more complex code, but constant extra memory).

---

## Edge Cases Interviewers Love
| Edge case | Why it matters | Expected handling |
|-----------|----------------|-------------------|
| Empty tree (`root == nullptr`) | Base case – should return 0. | Return 0 immediately. |
| Single node | The root is always good. | Count = 1. |
| Strictly decreasing values (e.g., 5 → 4 → 3) | Only the root is good. | Only the first node satisfies condition. |
| Strictly increasing values | Every node is good. | Counter equals number of nodes. |
| Deep skewed tree (depth = N) | Tests recursion‑stack limits. | Morris version works with O(1) space; recursive version may need tail‑recursion or increased stack size. |
| Negative values and `INT_MIN` | Ensure initial `maxSoFar` is set to `INT_MIN` (or `Long.MIN_VALUE` in Java) so that the root is correctly evaluated. |

---

## Mock Interview Follow‑up Q&A
**Q1:** *Can we solve this problem without modifying the tree (i.e., without Morris traversal)?*  
**A:** Yes. The recursive/iterative DFS that carries `maxSoFar` uses O(H) auxiliary space, which is acceptable for most interviews. Morris traversal is an extra optimization when the interviewer explicitly asks for O(1) space.

**Q2:** *What if the tree is a binary search tree? Does that help?*  
**A:** Not really. The “good” condition depends on the *path* maximum, not on the BST ordering property. The same O(N) traversal works regardless of BST structure.

**Q3:** *How would you adapt the solution to count “bad” nodes (nodes that are **not** good)?*  
**A:** The same traversal can be used; just increment a separate counter when `node.val < maxSoFar`.

**Q4:** *Can we parallelize this algorithm?*  
**A:** The optimal O(N) solution is inherently sequential because each node’s decision depends on the maximum from its ancestors. Parallelism would require a different formulation (e.g., bottom‑up DP on a rooted tree) but would add extra overhead and is rarely needed for this problem.

---

## References
- LeetCode 1448 – *Count Good Nodes in Binary Tree*
- Morris Traversal – *Threaded Binary Tree* technique (pre‑order version)

---

*Prepared by a Staff Software Engineer & Senior Technical Interviewer at a FAANG company.*
