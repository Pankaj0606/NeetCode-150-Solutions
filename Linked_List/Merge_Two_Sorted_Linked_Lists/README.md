# Merge Two Sorted Linked Lists

## Problem Statement
Given the heads of two sorted singly‑linked lists `l1` and `l2`, merge them into one sorted list. Return the head of the merged list.

**Input**: `ListNode* l1`, `ListNode* l2` (or the Java equivalents). Each list is sorted in non‑decreasing order.
**Output**: The head of a singly‑linked list that contains all nodes from `l1` and `l2` in sorted order.

## Core Challenges
1. **Preserve order while traversing two lists simultaneously** – you must always pick the smaller current node.
2. **Handle edge cases** – one or both lists may be empty, or they may contain duplicate values.
3. **Space constraints** – interviewers often ask for an in‑place solution that re‑uses the existing nodes.

## Approaches
### 1. Brute‑Force (Collect‑Sort‑Rebuild)
*Extract all values into an array, sort the array, then rebuild a new linked list.*
- **Time Complexity**: `O((n+m) log (n+m))` because of the sort.
- **Space Complexity**: `O(n+m)` for the auxiliary array and the newly allocated nodes.
- **When to use**: Good for a quick prototype or when you are not allowed to modify the input lists.

### 2. Better (Iterative Merge with New Nodes)
*Traverse both lists, always attach the smaller value to a new list.*
- **Time Complexity**: `O(n+m)` – each node is visited exactly once.
- **Space Complexity**: `O(n+m)` for the newly created nodes (the algorithm itself uses `O(1)` extra pointers).
- **When to use**: When you must keep the original lists untouched (e.g., functional style) but still want linear time.

### 3. Optimal (In‑Place Iterative Merge)
*Reuse the original nodes and only re‑wire the `next` pointers.*
- **Time Complexity**: `O(n+m)`.
- **Space Complexity**: `O(1)` auxiliary space (only a few pointers).
- **When to use**: This is the classic interview answer – it satisfies the problem constraints with the best possible resources.

## Transition from Brute‑Force to Optimal in an Interview
1. **Start with the obvious** – “I can dump everything into a vector, sort, and rebuild.” This shows you understand the problem.
2. **Identify the bottleneck** – sorting adds `log` factor and extra memory.
3. **Leverage the fact that both inputs are already sorted** – you can merge them in a single pass, just like the merge step of merge‑sort.
4. **Ask about mutability** – if the caller permits, you can reuse nodes; otherwise you fall back to the “better” approach that allocates new nodes.
5. **Present the in‑place version** – a dummy head simplifies pointer handling and guarantees `O(1)` extra space.

## Edge Cases Interviewers Love to Test
| Edge case | Why it matters |
|-----------|----------------|
| One list is `null` | Guarantees you correctly return the other list. |
| Both lists are `null` | Should return `null` without crashing. |
| Lists of unequal length | The tail of the longer list must be attached unchanged. |
| All elements of one list are smaller than the other | The algorithm must correctly attach the whole second list at the end. |
| Duplicate values | Verify that you keep *all* duplicates and maintain stability. |

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this recursively?*  
**A:** Yes. The recursive solution mirrors the iterative one: pick the smaller head, set its `next` to the result of merging the remainder. It runs in `O(n+m)` time but uses `O(n+m)` call‑stack space.

**Q2:** *What if the lists are doubly linked?*  
**A:** The same merge logic applies; you just need to update both `next` and `prev` pointers when re‑linking nodes.

**Q3:** *How would you modify the algorithm to merge `k` sorted lists?*  
**A:** Use a min‑heap (priority queue) to always extract the smallest current node among the `k` heads – overall `O(N log k)` where `N` is the total number of nodes.

**Q4:** *Is there any benefit to using a sentinel/dummy node?*  
**A:** It eliminates special‑case handling for the head of the merged list, making the code cleaner and less error‑prone.

---
*Prepared by a Staff Software Engineer & Senior Technical Interviewer at a FAANG company.*
