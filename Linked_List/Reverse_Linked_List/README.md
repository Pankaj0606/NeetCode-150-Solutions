# Reverse a Linked List

## Problem Statement
Given the head of a singly linked list, reverse the list, and return the reversed list's head.

## Core Challenges
- Understanding pointer manipulation without losing access to the rest of the list.
- Handling edge cases such as an empty list or a single‑node list.
- Communicating the thought process clearly during an interview.

## Approaches
### 1. Brute Force (Copy to Array)
**Idea**: Traverse the list, store each node in an auxiliary array/vector, then re‑link the nodes in reverse order.

**Complexity**
- Time: **O(N)** – one pass to collect nodes and another pass to re‑link.
- Space: **O(N)** – extra storage for the array.

**When to use**: Good for an initial solution when you want to avoid thinking about in‑place pointer changes. It shows you can solve the problem even if it isn’t optimal.

### 2. Better (Recursive Reversal)
**Idea**: Use recursion to reach the tail, then unwind the call stack, reversing links on the way back.

**Complexity**
- Time: **O(N)** – each node is visited once.
- Space: **O(N)** – recursion stack.

**When to use**: Demonstrates a clean, elegant solution and shows you understand recursion. Interviewers often ask follow‑up about stack space, which leads naturally to the optimal approach.

### 3. Optimal (Iterative In‑Place)
**Idea**: Iterate through the list once, reversing the `next` pointer of each node on the fly using three pointers (`prev`, `curr`, `next`).

**Complexity**
- Time: **O(N)**
- Space: **O(1)** – only constant extra variables.

**When to use**: This is the production‑ready solution. It’s the one you should end with after discussing the brute‑force and recursive versions.

## Transition Strategy in an Interview
1. **Start with the brute‑force** to get a correct solution quickly. Mention its O(N) space drawback.
2. **Ask the interviewer** if they care about space. If yes, propose the recursive version, explaining the trade‑off (still O(N) space but no explicit container).
3. **Lead to the optimal** by pointing out the recursion stack is extra space and can be eliminated with an iterative two‑pointer technique.
4. **Write the iterative code** and walk through a short example to prove correctness.

## Edge Cases Interviewers Love
- `head == null` (empty list)
- Single node list
- List with two nodes
- Very long list (to test for stack overflow in recursive solution)

## Mock Interview Follow‑up Q&As
**Q1:** *Can we reverse the list in groups of k nodes?*  
**A:** Yes, the same two‑pointer technique can be applied to each group, with careful handling of group boundaries.

**Q2:** *What if the list is doubly linked?*  
**A:** We would need to swap both `next` and `prev` pointers for each node; the iterative approach still works with O(1) space.

**Q3:** *How would you detect a cycle before reversing?*  
**A:** Use Floyd’s Tortoise‑Hare algorithm. If a cycle exists, reversing could cause an infinite loop, so we should break the cycle first.

**Q4:** *Can you reverse the list without modifying the original nodes (i.e., return a new reversed list)?*  
**A:** Yes, create new nodes while traversing the original list and prepend them to the new list – this is essentially the brute‑force array method but builds a fresh list.
