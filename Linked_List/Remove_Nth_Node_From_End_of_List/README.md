# Remove Nth Node From End of List

## Problem Statement & Core Challenges
- **Given** the head of a singly‑linked list and an integer `n`.
- **Goal**: Remove the *n-th* node from the end of the list and return the head of the modified list.
- **Core challenges**:
  1. Linked lists are **single‑directional** – you cannot index them like arrays.
  2. You must handle removal of the **head** node (when `n` equals the list length).
  3. Achieve the required time/space trade‑offs while keeping the code clean for interviewers.

---

## Approaches
### 1️⃣ Brute Force (Two‑Pass Length Calculation)
1. Traverse the list once to compute its length `L`.
2. Compute the index from the start: `idx = L - n` (0‑based).
3. Use a dummy node before `head` to simplify edge cases, traverse `idx` steps, splice out the target node.

**Complexities**
- Time: **O(L)** – two passes over the list.
- Space: **O(1)** – only a few pointers.

### 2️⃣ Better / Intermediate Optimization (Stack)
1. Push every node onto a stack while traversing the list.
2. Pop `n` nodes – the node on top is the predecessor of the node to delete.
3. Adjust pointers accordingly.

**Complexities**
- Time: **O(L)** – single pass + O(n) pops (still linear).
- Space: **O(L)** – the stack stores all nodes.

### 3️⃣ Optimal (Two‑Pointer / Fast‑Slow)
1. Initialise two pointers `fast` and `slow` at a dummy node before `head`.
2. Move `fast` `n+1` steps ahead (so the gap is `n` nodes).
3. Move both pointers together until `fast` reaches the end.
4. `slow->next` is the node to delete – splice it out.

**Complexities**
- Time: **O(L)** – single pass.
- Space: **O(1)** – constant extra pointers.

---

## Interview Narrative: From Brute Force to Optimal
1. **Start with the obvious** – “I’ll first compute the length, then delete the `(L‑n)`‑th node.” This shows you understand linked‑list traversal.
2. **Identify the pain point** – you need two passes and extra bookkeeping for the head case.
3. **Propose a data‑structure aid** – a stack gives you direct access to the predecessor after a single pass, but uses O(L) space.
4. **Lead to the classic two‑pointer technique** – “Can we keep a constant‑size window of size `n` while walking the list once?” This naturally yields the optimal solution.
5. **Explain the dummy node trick** – it removes special‑casing for head removal and keeps the code tidy.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters | Expected handling |
|-----------|----------------|-------------------|
| `n` equals list length (remove head) | Needs dummy or special case | Return `head->next` after deletion |
| Single‑node list, `n = 1` | List becomes empty | Return `nullptr` |
| `n = 0` (invalid) | Should be guarded against (often not in LeetCode) | Either assert or treat as no‑op |
| Very large `n` > length | Out‑of‑bounds – usually not given, but defensive code can return original list |
| List with duplicate values | Values don’t matter – removal is based on position |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this without a dummy node?*  
**A:** Yes, by handling the head removal as a separate `if (idx == 0)` case, but the dummy node keeps the code uniform and less error‑prone.

**Q2:** *What if the list is doubly linked?*  
**A:** The same two‑pointer idea works, but you could also move backwards from the tail after a single pass to find the node, still O(L) time.

**Q3:** *How would you modify the algorithm to return the removed node instead of the new head?*  
**A:** Keep a pointer to `slow->next` before splicing; return that pointer after adjusting links.

**Q4:** *Can you generalize this to “remove the k‑th node from the start and the n‑th from the end” in one pass?*  
**A:** Yes – maintain three pointers: one for the start index, one for the end gap, and a fast pointer to keep the distance. Adjust both deletions when the fast pointer hits the tail.

---

## TL;DR
- **Brute Force:** two passes, O(1) space.
- **Better:** stack, one pass, O(L) space.
- **Optimal:** fast/slow two‑pointer, one pass, O(1) space.
- Use a **dummy node** to simplify edge cases.
- Explain the evolution of ideas clearly – that’s what interviewers score.
