# Reorder Linked List

## Problem Statement
Given the head of a singly‑linked list, reorder it **in‑place** to follow the pattern:
```
L0 → Ln → L1 → Ln‑1 → L2 → Ln‑2 → …
```
where `L0` is the original head and `Ln` is the original tail.

### Core Challenges
1. **In‑place manipulation** – we cannot allocate another list of size *n* (except for O(1) auxiliary structures).
2. **Finding the middle** – we need to split the list into two halves efficiently.
3. **Reversing the second half** – the tail part must be reversed to enable the alternating merge.
4. **Merging alternately** – careful pointer updates are required to avoid cycles or lost nodes.

---

## Approaches
### 1️⃣ Brute‑Force (Copy‑to‑Array)
* **Idea** – Traverse the list, store pointers in a `vector`/`ArrayList`. Re‑wire the `next` pointers using the array order.
* **Complexities**
  * Time: **O(n)** – one pass to copy, one pass to reconnect.
  * Space: **O(n)** – extra array of node references.
* **When to use** – Quick prototype, good for explaining the problem to a non‑technical audience.

### 2️⃣ Better (Stack‑Based)
* **Idea** – Push all nodes onto a stack. Then pop from the stack while walking from the head, inserting popped nodes after the current node.
* **Complexities**
  * Time: **O(n)** – single traversal + stack operations.
  * Space: **O(n)** – the stack holds half of the nodes on average.
* **Why it’s better** – No random‑access array; still uses linear extra space but demonstrates a classic “reverse‑while‑traversing” trick.

### 3️⃣ Optimal (Two‑Pointer + Reverse + Merge)
* **Idea**
  1. **Find middle** using slow/fast pointers.
  2. **Reverse** the second half in‑place.
  3. **Merge** the two halves alternatingly.
* **Complexities**
  * Time: **O(n)** – three linear passes.
  * Space: **O(1)** – only a few pointer variables.
* **Why it’s optimal** – Meets the interview expectation of *O(n) time, O(1) extra space*.

---

## Transition Narrative (Brute → Optimal)
1. **Start with the array solution** – easy to reason about, guarantees correctness.
2. **Observe the pattern** – the second half of the list is used in reverse order. This suggests a *stack* or *reverse* operation.
3. **Introduce the stack** – eliminates the need for random access but still O(n) space.
4. **Ask the interviewer** – *Can we do it without extra storage?* → Leads to the two‑pointer technique.
5. **Explain the three‑step optimal method** – each step is a classic linked‑list sub‑problem (mid‑find, reverse, merge).

---

## Edge Cases Interviewers Love
| Edge case | Reason it trips candidates |
|-----------|----------------------------|
| Empty list (`null`) | Forgetting a guard clause leads to segfaults. |
| Single node | No reordering needed; must still terminate correctly. |
| Two nodes | After reordering the list should stay the same; pointer handling is subtle. |
| Odd vs. even length | Middle node handling differs – ensure the middle is not duplicated. |
| Very long list (10⁵+ nodes) | Tests O(1) space and no recursion stack overflow. |

---

## Mock Interview Follow‑up Q&A
**Q1:** *Why can’t we simply reverse the whole list and then interleave?*  
**A:** Reversing the whole list would lose the original forward order of the first half. We only need the **second half** reversed.

**Q2:** *Can we solve this recursively?*  
**A:** Yes, by recursively processing the inner sub‑list, but recursion depth becomes O(n) → possible stack overflow for large inputs, violating O(1) auxiliary space.

**Q3:** *What if the list is a doubly‑linked list?*  
**A:** The optimal algorithm becomes even simpler because we can walk from both ends without extra reversal, still O(1) space.

**Q4:** *How would you adapt the solution for a circular linked list?*  
**A:** Break the circle at the head, apply the same algorithm, then reconnect the tail to the head after reordering.

---

## Code Implementations
Below are ready‑to‑submit solutions in **C++** and **Java** for all three approaches.
