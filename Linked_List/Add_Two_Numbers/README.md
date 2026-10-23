# Add Two Numbers

## Problem Statement
You are given two non‑empty singly linked lists representing two non‑negative integers. The digits are stored **in reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list, also in reverse order.

**Example**
```
Input:  (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

### Core Challenges
1. **Different lengths** – the two lists may not be the same size.
2. **Carry propagation** – a digit sum can be >= 10, requiring a carry to the next node.
3. **In‑place vs extra space** – interviewers love to discuss whether we can solve the problem with O(1) auxiliary space.
4. **Edge cases** – empty list, single‑node list, final carry creating a new most‑significant digit.

---

## Approaches
### 1️⃣ Brute‑Force (Convert → Add → Re‑build)
*Traverse each list, build the integer as a string, reverse the string to obtain the true order, perform big‑integer addition on the strings, then convert the result back to a linked list.*

- **Time Complexity**: O(N + M) for traversals + O(K) for string addition, where K = max(N, M) → **O(N+M)**.
- **Space Complexity**: O(N+M) for the two intermediate strings and the result string → **O(N+M)**.
- **Pros**: Very easy to explain; demonstrates understanding of conversion.
- **Cons**: Not truly O(1) extra space, and real‑world code would avoid converting to strings.

### 2️⃣ Better (Two Stacks)
*Push all digits of each list onto a stack, then pop to simulate addition from the most‑significant digit. Build the answer by inserting each new node at the head.*

- **Time Complexity**: O(N+M) – one pass to fill stacks, one pass to pop and build.
- **Space Complexity**: O(N+M) for the two stacks.
- **Pros**: Still simple, avoids string conversion, works for any length.
- **Cons**: Still uses O(N) auxiliary space.

### 3️⃣ Optimal (One‑Pass Iterative with Carry)
*Iterate both lists simultaneously, adding corresponding digits plus a carry. Create nodes on‑the‑fly and link them. When one list ends, treat its missing digits as 0. After the loop, if a carry remains, append a final node.*

- **Time Complexity**: O(N+M).
- **Space Complexity**: O(1) auxiliary (output list does not count).
- **Pros**: Minimal extra memory, the classic LeetCode solution, interview‑ready.
- **Cons**: Slightly more bookkeeping (carry handling).

---

## From Brute‑Force to Optimal – How to Explain in an Interview
1. **Start with the simplest mental model** – converting to numbers makes the problem trivial, showing you understand the core arithmetic.
2. **Identify the pain point** – converting to a string (or a big integer) uses extra memory proportional to the input size, which is unnecessary because the list already stores the digits.
3. **Introduce a data‑structure that respects the order** – a stack reverses the list without extra conversion, reducing mental overhead.
4. **Show that we can do even better** – we don’t need any extra container; we can walk the lists once, keep a running carry, and build the result directly. This demonstrates mastery of in‑place algorithms.
5. **Summarize the trade‑offs** – O(N) space vs O(1) space, constant‑factor work, readability vs optimality.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters |
|-----------|----------------|
| One list is `null` (empty) | Guarantees you handle missing input gracefully. |
| Different lengths (e.g., 1‑node vs 5‑node) | Tests loop termination and default‑zero handling. |
| Final carry creates a new node (e.g., 9→9 + 1) | Checks if you add the extra most‑significant digit. |
| All zeros (0 → 0) | Ensures you don’t produce extra leading zeros. |
| Very long lists (10⁵+ nodes) | Validates O(N) time and O(1) space solution. |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this problem without modifying the input lists?*  
**A:** Yes. All three approaches treat the input as read‑only. The optimal solution creates a brand‑new list, leaving the originals untouched.

**Q2:** *What if the digits were stored in forward order?*  
**A:** We would need to reverse the lists first (or use stacks/recursion) to align the least‑significant digits, then apply the same carry logic. The stack‑based method becomes the natural choice.

**Q3:** *How would you adapt the solution for a doubly linked list?*  
**A:** With a doubly linked list we could traverse from the tail (most‑significant digit) directly, eliminating the need for extra stacks. The algorithm would be identical to the forward‑order case.

**Q4:** *Is there any scenario where the brute‑force string conversion is preferable?*  
**A:** In a language that already provides arbitrary‑precision integers (e.g., Python's `int`), converting to a number and adding may be the simplest and still O(N) time, though it still uses O(N) extra space for the string representation.

---

**Bottom line:** Master the optimal one‑pass solution, but be ready to discuss the simpler stack‑based and conversion‑based variants to show depth of understanding.
