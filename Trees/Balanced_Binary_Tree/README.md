# Balanced Binary Tree

## Problem Statement & Core Challenges
*Given the `root` of a binary tree, determine if it is height‑balanced.*
A binary tree is **height‑balanced** if for every node, the difference between the heights of its left and right sub‑trees is at most 1.

The core challenges are:
1. **Defining height** – the number of edges on the longest path from a node down to a leaf.
2. **Checking the balance condition for *every* node**, not just the root.
3. **Avoiding repeated work** – naïve solutions recompute subtree heights many times, leading to O(N²) time on skewed trees.

---

## Approaches
### 1️⃣ Brute‑Force (O(N²) time, O(H) space)
* For each node we compute the height of its left and right sub‑trees via a separate recursive call.
* After obtaining the heights we check the balance condition and recursively repeat the process for the children.
* **Why it’s O(N²)**: In a completely unbalanced tree, `height` is called for each node, and each call traverses O(N) nodes again.

### 2️⃣ Better / Intermediate Optimization (O(N log N) time, O(H) space)
* Perform a **post‑order traversal** that returns a pair `(isBalanced, height)` for each subtree.
* The height of a node is computed **once**, but we still propagate the `isBalanced` flag upwards without early termination.
* In a balanced tree the height is O(log N), giving O(N log N) overall. In the worst case (skewed) it degrades to O(N²), but the constant factor is much smaller than the brute‑force.

### 3️⃣ Optimal (O(N) time, O(H) space)
* Use a **single post‑order DFS** that returns the height of a subtree.
* If any subtree is found unbalanced, we return `-1` immediately (sentinel value). The caller propagates `-1` upwards, cutting off all further work.
* This guarantees each node is visited **once**, yielding linear time.

---

## How to Explain the Transition in an Interview
1. **Start with the obvious** – “I would compute the height of left and right sub‑trees for every node and compare them.” Mention the O(N²) cost.
2. **Identify the repeated work** – “We are recomputing heights for the same sub‑trees many times.”
3. **Introduce a helper that returns both height and balance** – “Now each node’s height is computed only once, giving us O(N log N) on a balanced tree.”
4. **Push further with early exit** – “If a subtree is already unbalanced we don’t need its exact height; we can propagate a sentinel value (`-1`). This stops the recursion early and guarantees O(N).”
5. **Summarize** – “Thus we move from a naïve double‑traversal to a single‑pass post‑order traversal with early termination.”

---

## Edge Cases Interviewers Love to Test
| Edge case | Why it matters |
|-----------|----------------|
| Empty tree (`null`) | Should return `true` – no nodes means trivially balanced. |
| Single node | Height difference is 0. |
| Completely skewed tree (linked‑list shape) | Height difference grows linearly; algorithm must detect imbalance quickly. |
| Tree where only the deepest leaf breaks the balance | Tests that the solution checks *every* node, not just the root. |
| Large balanced tree (≈10⁵ nodes) | Ensures the solution is O(N) and does not overflow the call stack (use recursion depth ≈ height). |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this iteratively to avoid recursion depth issues?*  
**A:** Yes. Perform a post‑order traversal using an explicit stack and store a map from node to its computed height. The sentinel `-1` technique works the same way.

**Q2:** *What if the tree is stored as an array (heap representation) instead of pointers?*  
**A:** The same logic applies – compute heights using indices. The recursive/iterative approach just translates to index arithmetic.

**Q3:** *How would you modify the algorithm to return the *minimum* number of nodes that need to be removed to make the tree balanced?*  
**A:** That becomes a DP problem. For each node we would compute the size of the largest balanced subtree rooted at that node and then derive the answer as `totalNodes - maxBalancedSize`.

**Q4:** *Is there a way to achieve O(1) extra space?*  
**A:** Using Morris traversal we can achieve O(1) auxiliary space, but the implementation is considerably more complex and rarely expected in interviews.

---

**Bottom line:** Master the post‑order sentinel pattern – it’s the go‑to solution for any “property of sub‑trees” problem (balance, BST validation, diameter, etc.).
