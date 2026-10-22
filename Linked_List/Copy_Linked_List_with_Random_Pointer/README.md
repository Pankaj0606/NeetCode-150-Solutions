# Copy List with Random Pointer

## Problem Statement
Given a linked list where each node contains an additional **random** pointer which could point to any node in the list or `null`, return a **deep copy** of the list. The deep copy should consist of exactly new nodes, where each new node's `next` and `random` pointers point to the corresponding new nodes in the copied list.

```
class Node {
    int val;
    Node *next;
    Node *random;
    Node(int _val) { val = _val; next = nullptr; random = nullptr; }
}
```

### Core Challenges
1. **Preserving random relationships** – the `random` pointer can point arbitrarily, not just to the next node.
2. **Avoiding O(N²) scans** – a naïve scan for each random pointer leads to quadratic time.
3. **Space constraints** – interviewers often ask for an O(1) extra‑space solution.
4. **Edge cases** – empty list, single node, self‑referencing random pointers, and multiple nodes sharing the same random target.

---

## Approaches
### 1️⃣ Brute‑Force (O(N²) time, O(1) extra space)
*Create a copy list with correct `next` links first. Then, for each original node, linearly search the original list to locate the node referenced by its `random` pointer and set the corresponding copy's `random`.

**Pros**: No auxiliary data structures.
**Cons**: Quadratic time – unacceptable for large inputs.

### 2️⃣ Better / Intermediate (O(N) time, O(N) space)
Use a hash map (`unordered_map<Node*, Node*>` in C++ or `HashMap<Node, Node>` in Java) to store a mapping from each original node to its newly created copy.
1. First pass – copy every node (only `val`).
2. Second pass – assign `next` and `random` using the map.

**Pros**: Linear time, easy to explain.
**Cons**: Extra O(N) space.

### 3️⃣ Optimal (O(N) time, O(1) extra space)
Interleave copied nodes with the original list:
1. **Weave** – for each original node `orig`, insert its copy `copy` right after it (`orig->next = copy; copy->next = nextOrig`).
2. **Assign random** – `copy->random = orig->random ? orig->random->next : nullptr` because the copy of any node is the next node of the original.
3. **Unweave** – detach the copied list from the interleaved structure, restoring the original list.

**Pros**: Constant extra space, linear time – the gold standard.
**Cons**: Slightly trickier to code; must be careful to restore the original list.

---

## Transition Narrative (Brute → Optimal)
1. **Identify the bottleneck** – the O(N²) scan for random pointers.
2. **Introduce a map** – reduces the lookup to O(1) but adds O(N) space.
3. **Ask the interviewer** – *Can we get rid of the extra map?* This signals you’re thinking about space optimization.
4. **Observe the structure** – each original node already has a direct link to its copy if we place the copy right after it. This observation leads to the interleaving technique.
5. **Explain the three‑step process** (weave → assign random → unweave) and why each step is O(N).
6. **Conclude** – we achieve O(N) time and O(1) extra space, which is optimal.

---

## Edge Cases Interviewers Love
| Case | Why it matters |
|------|----------------|
| `head == nullptr` | Handles empty input. |
| Single node where `random` points to itself | Tests self‑reference handling. |
| Multiple nodes sharing the same `random` target | Ensures you don’t create duplicate copies of the same target. |
| Long chain with alternating `null` and non‑null randoms | Checks robustness of pointer assignments. |

---

## Mock Interview Follow‑up Q&A
**Q1:** *Can we solve this problem recursively?*  
**A:** Yes, a recursive solution with memoization (hash map) works, but it still uses O(N) extra space for the map and the call stack.

**Q2:** *What if the list is doubly linked (has `prev` pointers) – does the optimal approach still work?*  
**A:** The weaving technique still works; you just need to also copy and later restore the `prev` links while unweaving.

**Q3:** *How would you modify the optimal solution if the nodes also stored a `child` pointer (like a multilevel list)?*  
**A:** You’d need to recursively copy each child list, but the O(1) space guarantee only holds for the single‑level case.

**Q4:** *Is it possible to achieve O(N) time and O(1) space without modifying the original list?*  
**A:** No – any O(1) extra‑space algorithm must temporarily alter the original structure (e.g., weaving) because we need a way to map originals to copies without extra storage.

---

## Summary
- **Brute‑Force:** O(N²) time, O(1) space – simple but inefficient.
- **Hash‑Map:** O(N) time, O(N) space – practical and easy to code.
- **Weaving (Optimal):** O(N) time, O(1) space – the technique interviewers love to see.

Make sure to discuss each trade‑off, walk through the three‑step optimal algorithm, and cover the edge cases listed above.
