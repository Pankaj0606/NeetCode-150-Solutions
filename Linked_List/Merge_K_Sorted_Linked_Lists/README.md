# Merge k Sorted Linked Lists

## Problem Statement
Given an array `lists` of `k` singly‑linked lists, each list is sorted in ascending order. Merge all the lists into one sorted linked list and return its head.

## Core Challenges
* Dealing with an unknown number of lists (`k`).
* Maintaining the overall sorted order while only having local access to each list’s head.
* Achieving the best possible time‑complexity without excessive auxiliary space.

## Approaches
### 1️⃣ Brute‑Force (Collect‑and‑Sort)
**Idea**: Traverse every node, dump its value into a vector, sort the vector, then rebuild a new linked list.

**Complexities**
* **Time**: `O(N log N)` where `N` is the total number of nodes across all lists (sorting dominates).
* **Space**: `O(N)` for the auxiliary array of values.

**When to use**: Good for a quick prototype or when `k` is tiny and memory isn’t a concern.

---
### 2️⃣ Better – Min‑Heap (Priority Queue)
**Idea**: Push the head of each non‑empty list into a min‑heap keyed by node value. Repeatedly pop the smallest node, attach it to the result, and push its `next` node (if any) back into the heap.

**Complexities**
* **Time**: `O(N log k)` – each node is pushed/popped once, heap size never exceeds `k`.
* **Space**: `O(k)` for the heap.

**When to use**: The classic interview solution; works well for large `k` and large `N`.

---
### 3️⃣ Optimal – Divide & Conquer
**Idea**: Repeatedly merge pairs of lists (like the merge step of merge‑sort). Recursively merge the left half and the right half, then merge the two resulting lists.

**Complexities**
* **Time**: `O(N log k)` – each level merges all nodes once, and there are `log k` levels.
* **Space**: `O(log k)` recursion stack (no extra heap beyond the two‑list merge which is `O(1)`).

**When to use**: Same asymptotic bounds as the heap but with lower constant factors and no extra data structures.

---
## Transition Narrative (Brute → Better → Optimal)
1. **Start with the obvious** – “Collect everything, sort, rebuild.” This shows you understand the problem and can produce a correct solution.
2. **Identify the bottleneck** – Sorting all `N` values is `O(N log N)`. Since each list is already sorted, we can exploit that order.
3. **Introduce a data structure** – A min‑heap gives us the next smallest element in `O(log k)`. Explain why the heap size is bounded by `k`.
4. **Push further** – The heap still incurs `log k` overhead per node. By merging lists in pairs (divide‑and‑conquer) we achieve the same `O(N log k)` but with only `O(1)` work per merge step and a tiny recursion stack.
5. **Conclude** – Both heap and divide‑and‑conquer are optimal; you can pick whichever you’re more comfortable implementing.

---
## Edge Cases Interviewers Love
| Edge case | Why it matters | How we handle |
|-----------|----------------|--------------|
| `lists` is empty or all `null` | Should return `null` without errors. | Early return if result head stays `null`. |
| Single list (`k = 1`) | No merging needed. | All approaches naturally return the original list. |
| Very long list with many duplicates | Tests stability and pointer handling. | Merges preserve order; heap comparator works with equal values. |
| Varying lengths (some lists empty) | Ensures you skip `null` heads correctly. | Skip `null` when initializing heap or during recursion. |

---
## Mock Interview Follow‑up Q&A
**Q1:** *Can we improve the space usage of the heap solution?*  
**A:** The heap already uses `O(k)` space, which is optimal because we must at least keep a reference to the current smallest candidate from each list.

**Q2:** *What if the lists are stored in a linked list of lists instead of an array?*  
**A:** The same algorithms apply; we just need to traverse that outer list to collect heads for the heap or to perform divide‑and‑conquer.

**Q3:** *How would you adapt the solution for a doubly‑linked list?*  
**A:** The merge logic stays identical; we only need to update both `next` and `prev` pointers when linking nodes.

**Q4:** *Is there a way to make the divide‑and‑conquer iterative?*  
**A:** Yes – repeatedly merge lists in pairs in a bottom‑up fashion (similar to iterative merge‑sort) using a loop that doubles the interval each pass.

---
## TL;DR
* **Brute‑Force:** Collect → sort → rebuild (`O(N log N)` time, `O(N)` space).
* **Heap:** Min‑heap of heads (`O(N log k)` time, `O(k)` space).
* **Divide‑Conquer:** Pairwise merges (`O(N log k)` time, `O(log k)` recursion stack).

Pick the approach that best matches the constraints you’re given, and be ready to explain why you’d move from one to the next during an interview.
