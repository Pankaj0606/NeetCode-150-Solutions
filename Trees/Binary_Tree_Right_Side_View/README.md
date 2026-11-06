# Binary Tree Right Side View

## Problem Statement & Core Challenges
Given the `root` of a binary tree, imagine yourself standing on the **right side** of it. Return the values of the nodes you can see ordered from top to bottom.

* The tree can be empty.
* Nodes may have only left children, only right children, or both.
* The challenge is to capture **the right‑most node at each depth** efficiently.

## Approaches
### 1️⃣ Brute‑Force (Level‑order collection)
*Perform a BFS, store *all* nodes of each level in a temporary vector, then pick the last element.*

**Complexities**
- Time: `O(N)` – each node is visited once.
- Space: `O(N)` – we keep a full list of nodes per level (worst‑case a full leaf level).

### 2️⃣ Better (Level‑order, last‑node capture)
*While doing BFS, note the size of the current level. The node processed last in that loop is the right‑most one – push its value directly to the answer.*

**Complexities**
- Time: `O(N)` – still linear.
- Space: `O(W)` where `W` is the maximum width of the tree (at most `N/2`). No extra per‑level storage.

### 3️⃣ Optimal (DFS – right first)
*Do a pre‑order DFS that visits the **right child before the left child**. Keep track of the current depth. The first time we reach a depth we add the node’s value – this will always be the right‑most node for that depth.*

**Complexities**
- Time: `O(N)` – each node visited once.
- Space: `O(H)` recursion stack, where `H` is the tree height (best case `O(log N)`, worst case `O(N)`).

## Interview Narrative: From Brute‑Force to Optimal
1. **Start with the obvious BFS** – “let’s look at each level and pick the last node”. This shows you understand level‑order traversal.
2. **Identify the waste** – we stored *all* nodes of a level only to discard everything but the last one.
3. **Refine the BFS** – keep only a counter for the level size and record the last node on the fly. This reduces auxiliary space.
4. **Push further – DFS** – realize that we don’t need a queue at all. By traversing right‑first we guarantee the first node we encounter at a new depth is the answer. This eliminates the explicit level container and gives the cleanest code.

Demonstrating this progression shows problem‑solving depth and awareness of trade‑offs.

## Edge Cases Interviewers Love
| Edge case | Why it matters |
|-----------|----------------|
| `null` root | Should return an empty list. |
| Single node tree | Output is just that node. |
| Left‑skewed tree (only left children) | Right view equals the leftmost nodes – tests that you don’t assume a right child exists. |
| Right‑skewed tree (only right children) | Every node is visible – ensures you handle deep recursion/iteration without overflow. |
| Complete binary tree | Verifies correct ordering across multiple levels. |

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this without extra space?*  
**A:** The DFS approach uses only the recursion stack (`O(H)`). If recursion is disallowed, an iterative stack mimics the same space usage.

**Q2:** *What if the tree is extremely deep (e.g., 10⁵ nodes) – will recursion overflow?*  
**A:** In production you’d switch to an explicit stack (iterative DFS) or the BFS approach which uses a queue but still `O(W)` memory. LeetCode’s constraints usually keep recursion safe.

**Q3:** *How would you modify the algorithm to return the **left** side view instead?*  
**A:** For BFS, capture the **first** node of each level. For DFS, traverse **left before right** and record the first node at each depth.

**Q4:** *Can we compute both left and right side views in a single traversal?*  
**A:** Yes – during BFS keep both the first and last node of each level, or during DFS maintain two arrays (one for left‑first, one for right‑first) while recursing.

---
*Prepared for a FAANG interview – clear explanation, optimal code, and deeper discussion points.*
