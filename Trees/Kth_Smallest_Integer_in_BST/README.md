# Kth Smallest Integer in BST

## Problem Statement
Given the `root` of a **Binary Search Tree (BST)** and an integer `k`, return the k‑th smallest element in the BST. The BST property guarantees that an **in‑order traversal** visits nodes in ascending order.

### Core Challenges
1. **In‑order ordering** – leveraging the BST property to avoid sorting.
2. **Space constraints** – can we achieve O(1) auxiliary space?
3. **Early termination** – stop traversing once the k‑th element is found.
4. **Edge‑case robustness** – handling skewed trees, duplicate values, and invalid `k`.

---

## Approaches

### 1️⃣ Brute‑Force (Full In‑order + Array)
*Perform a complete in‑order traversal, store every node value in a vector/list, then index `k‑1`.*

**Complexities**
- Time: **O(N)** – every node is visited.
- Space: **O(N)** – extra array holds all values.

**When to use** – quick to code, good for the first iteration in an interview to show you understand the BST ordering.

---

### 2️⃣ Better (Iterative In‑order with Early Stop)
*Use an explicit stack to simulate recursion. Pop nodes one‑by‑one, decrement `k`, and return as soon as `k` reaches zero.*

**Complexities**
- Time: **O(N)** worst‑case (when `k = N`).
- Space: **O(H)** – only the stack for the current path, where `H` is the tree height (average `O(log N)` for balanced trees).

**Why it’s better** – eliminates the need for an auxiliary array and stops early, which is a natural optimisation after the brute‑force.

---

### 3️⃣ Optimal (Morris In‑order Traversal – O(1) Space)
*Temporarily thread the tree by linking a node's inorder predecessor to the current node. This allows an in‑order walk without recursion or a stack.*

**Complexities**
- Time: **O(N)** – each edge is visited at most twice.
- Space: **O(1)** – only a few pointers, no recursion/stack.

**Why it’s optimal** – meets the interviewer's “can you do it in O(1) extra space?” challenge while still being linear time.

---

## Transition Narrative (Brute → Better → Optimal)
1. **Start with the brute‑force** to demonstrate you know the in‑order property.
2. **Point out the waste** of storing the whole traversal; suggest stopping early.
3. **Introduce a stack** to achieve early termination with only O(H) space.
4. **Ask the interviewer** if they care about the auxiliary space. If yes, bring up Morris traversal as the O(1) solution.
5. **Explain Morris** briefly: create temporary right‑thread links, visit nodes, then restore the tree.

This progression shows systematic optimisation and a deep understanding of tree traversals.

---

## Edge Cases Interviewers Love
| Edge Case | Why It’s Tricky | Expected Behaviour |
|-----------|----------------|--------------------|
| `k = 1` (smallest element) | Must stop at the very first node visited. | Return the left‑most node value. |
| `k = N` (largest element) | Traversal must reach the rightmost node. | Return the right‑most node value. |
| Skewed tree (all left or all right) | Height = N, stack depth = N for the iterative version. | Still works; space becomes O(N) in worst case. |
| Duplicate values | BST definition may allow duplicates on either side. | In‑order still yields sorted order; k‑th smallest respects duplicates. |
| Invalid `k` (e.g., `k > N` or `k <= 0`) | Must guard against out‑of‑bounds. | Return `-1` or throw an exception (LeetCode guarantees valid `k`). |

---

## Mock Interview Follow‑up Q&A
1. **Q:** *Can we solve this without modifying the tree (i.e., without Morris)?*  
   **A:** Yes – the iterative stack solution gives O(H) space, which is optimal if O(1) extra space isn’t required.
2. **Q:** *What if the tree is immutable and we cannot create threads?*  
   **A:** Use the iterative approach; it respects immutability and still stops early.
3. **Q:** *How would you extend this to “k‑th largest” instead?*  
   **A:** Perform a **reverse in‑order** (right → node → left) traversal; the same early‑stop logic applies.
4. **Q:** *Can we answer multiple queries (`k` values) efficiently?*  
   **A:** Pre‑process an in‑order array once (O(N) time, O(N) space) and answer each query in O(1). For dynamic updates, consider an Order‑Statistic Tree (augmented BST) or a Fenwick/Segment tree on the inorder indices.

---

## Summary
- **Brute‑force:** Simple, O(N) space.
- **Iterative early‑stop:** O(H) space, stops as soon as the answer is found.
- **Morris traversal:** O(1) extra space, still O(N) time.

Understanding each step and being able to articulate the trade‑offs is what interviewers look for.

---

*Happy coding!*
