# Linked List Cycle Detection

## Problem Statement & Core Challenges
**Problem**: Given the head of a singly‑linked list, determine whether the list contains a cycle. A cycle exists if you can start at some node and, by following `next` pointers, return to the same node again.

**Core challenges**:
1. **O(1) extra space** – interviewers love to see solutions that don’t allocate auxiliary data structures.
2. **Preserving the list** – many clever tricks (e.g., mutating pointers) risk corrupting the input; you must be able to explain how you restore the original list if you modify it.
3. **Edge‑case awareness** – empty list, single node without a cycle, single node that points to itself, very long lists, etc.

---

## Approaches
### 1️⃣ Brute‑Force (Hash‑Set / Visited Set)
```text
Traverse the list while storing each visited node pointer in a hash set.
If we encounter a node that is already in the set, a cycle exists.
```
**Time Complexity**: O(N) – each node is visited at most once.
**Space Complexity**: O(N) – we store up to N node references.

### 2️⃣ Better (In‑Place List Reversal)
```text
While walking the list, reverse the `next` pointers on‑the‑fly.
If we ever reach a `nullptr`, the list terminates → no cycle.
If we encounter the original `head` again, we have looped back → cycle.
After detection we reverse the list a second time to restore the original order.
```
**Time Complexity**: O(N) – two passes (reverse + restore).
**Space Complexity**: O(1) – only a few pointer variables.
**When to use**: Shows you can achieve O(1) space without Floyd’s algorithm, but you must discuss the cost of mutating the list and the need to restore it.

### 3️⃣ Optimal (Floyd’s Tortoise & Hare)
```text
Two pointers start at the head:
- *slow* moves one step each iteration.
- *fast* moves two steps each iteration.
If a cycle exists, fast will eventually lap slow and they meet.
If fast reaches `nullptr`, the list terminates → no cycle.
```
**Time Complexity**: O(N) – each pointer traverses at most N nodes.
**Space Complexity**: O(1) – only two pointers.
**Why interviewers love it**: Constant space, no list mutation, and the “two‑pointer” pattern is a reusable tool for many linked‑list problems.

---

## Transition Narrative (Brute → Better → Optimal)
1. **Start with the obvious** – “I would keep a hash set of visited nodes.” This demonstrates correctness and O(N) time.
2. **Show awareness of space** – “The hash set uses O(N) extra memory; can we do better?”
3. **Introduce in‑place reversal** – “If we are allowed to temporarily mutate the list, we can reverse the links while walking. This drops space to O(1) but we must restore the list before returning.”
4. **Present Floyd’s algorithm** – “There is an even cleaner O(1)‑space solution that never mutates the list: the tortoise‑and‑hare technique.”
5. **Explain why Floyd is preferred** – No side‑effects, constant extra memory, and it’s the canonical solution most interviewers expect.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters | Expected handling |
|-----------|----------------|-------------------|
| `head == nullptr` | Empty list should return `false`. | Immediate return.
| Single node, `next == nullptr` | No cycle. | Return `false`.
| Single node, `next == head` | Self‑loop – a valid cycle. | Return `true`.
| Very long acyclic list (e.g., 10⁶ nodes) | Tests for O(N) time and no stack overflow. | Linear scan works.
| Cycle that starts deep in the list | Ensures algorithm doesn’t stop early. | Detects when fast meets slow inside the loop.
| List with two nodes forming a cycle | Small cycle detection. | Fast pointer jumps over the second node and meets slow.

---

## Mock Interview Follow‑up Q&As
**Q1.** *Can we solve this problem without extra memory *and* without modifying the list?*  
**A1.** Yes – Floyd’s Tortoise & Hare does exactly that. It uses two pointers moving at different speeds; if a cycle exists they eventually meet.

**Q2.** *What if the list is a doubly‑linked list? Does the solution change?*  
**A2.** The same approaches work. The hash‑set method is unchanged. For Floyd’s algorithm we only need the `next` direction, so it works identically. In‑place reversal is even easier because we can walk backwards, but we still must restore both `next` and `prev` pointers.

**Q3.** *How would you adapt the algorithm to return the node where the cycle begins?*  
**A3.** After detecting a meeting point with Floyd’s algorithm, reset one pointer to `head` and move both one step at a time; the node where they meet again is the start of the cycle.

**Q4.** *Is there any scenario where the in‑place reversal approach is preferable to Floyd’s?*  
**A4.** Only when you are explicitly allowed to mutate the list and you need to guarantee O(1) space *and* you want to avoid the two‑pointer “fast‑slow” pattern (e.g., in a language without easy pointer arithmetic). In practice Floyd’s method is preferred because it leaves the list untouched.

---

**Bottom line**: Know the hash‑set baseline, be ready to discuss O(1)‑space tricks, and master Floyd’s Tortoise & Hare – it’s the gold standard for cycle detection.
