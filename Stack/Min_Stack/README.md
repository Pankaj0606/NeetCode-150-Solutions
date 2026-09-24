# Min Stack

## Problem Statement
Implement a stack that supports the following operations in **O(1)** time:
- `push(x)`: Push element `x` onto the stack.
- `pop()`: Remove the element on top of the stack.
- `top()`: Get the top element.
- `getMin()`: Retrieve the minimum element in the stack.

The classic challenge is to maintain the current minimum without scanning the whole stack on each `getMin()` call.

## Core Challenges
1. **Constant‑time minimum** – naive scanning makes `getMin()` **O(n)**.
2. **Space vs. Time trade‑off** – auxiliary data structures can give O(1) time but may use extra space.
3. **Edge‑case handling** – empty stack operations, duplicate minimum values, and integer overflow when encoding values.

## Approaches
### 1️⃣ Brute‑Force (O(n) `getMin`)
- **Idea**: Use a single stack for values. When `getMin()` is called, iterate through the stack to find the smallest element.
- **Complexities**: `push`, `pop`, `top` → **O(1)**; `getMin` → **O(n)**; **Space** → **O(n)** (the stack itself).
- **When to use**: Quick prototype or when `getMin` is rarely called.

### 2️⃣ Better – Two‑Stack Method (O(1) all ops, O(n) extra space)
- **Idea**: Keep a secondary stack `minStack` that stores the current minimum after each push. When pushing, also push onto `minStack` if the new value is ≤ current minimum. On pop, pop from `minStack` if the popped value equals the current minimum.
- **Complexities**: All operations **O(1)**; **Space** → **O(n)** (both stacks).
- **Why it’s better**: Guarantees constant‑time `getMin` at the cost of extra space.

### 3️⃣ Optimal – Single‑Stack Encoding (O(1) time, O(1) extra space)
- **Idea**: Store *encoded* values in the main stack when a new element becomes the new minimum. The encoding formula is `encoded = 2*x - previousMin`. The variable `minVal` always holds the real current minimum.
  - **Push**: If `x` ≥ `minVal`, push `x`. Otherwise push the encoded value and update `minVal = x`.
  - **Pop**: If the popped value `< minVal`, it means it was an encoded value; recover the previous minimum with `minVal = 2*minVal - encoded`.
  - **Top**: If the top value `< minVal`, the real top is `minVal`; otherwise it is the stored value.
- **Complexities**: All operations **O(1)**; **Space** → **O(n)** for the stack itself but **O(1)** auxiliary space.
- **Edge‑case safety**: Use `long long` (or `long`) to avoid overflow when encoding.

## Transition Narrative (Interview Friendly)
1. **Start with the obvious** – a normal stack and a linear scan for `getMin`. Mention the time penalty.
2. **Introduce the auxiliary stack** – explain how keeping a parallel min‑stack gives constant‑time queries, and discuss duplicate minima handling (`≤` condition).
3. **Push further** – ask the interviewer if we can reduce the extra space. Present the encoding trick, walk through the math, and highlight overflow handling.
4. **Conclude** – summarize trade‑offs and let the interviewer choose the most appropriate version for the given constraints.

## Edge Cases Interviewers Love
- Performing `pop` or `top` on an empty stack (should be no‑op or throw, depending on spec).
- Pushing duplicate minimum values (e.g., `[5, 3, 3, 2]`). Ensure `minStack` correctly tracks count.
- Large positive/negative integers that could overflow the encoding formula – use a wider type.
- Sequence of operations that alternates between new minima and larger values to test the recovery logic.

## Mock Interview Follow‑up Q&As
**Q1:** *Why do we use `<=` when pushing onto `minStack`?*  
**A:** To correctly handle duplicate minima. If we used `<` only, popping one of the duplicate minima would incorrectly change the reported minimum.

**Q2:** *Can we achieve O(1) time without any extra space at all?*  
**A:** Not with a plain stack; we need at least the stack itself to store elements. The encoding method uses **O(1)** additional variables, which is the optimal auxiliary‑space solution.

**Q3:** *How does the encoding method avoid overflow?*  
**A:** By promoting the calculation to a 64‑bit type (`long long`/`long`). The original constraints (32‑bit ints) guarantee the encoded value fits in 64 bits.

**Q4:** *What if the API required `peekMin()` without modifying the stack?*  
**A:** Both the two‑stack and encoding solutions already provide `getMin()` in O(1) without altering the data structure, so no extra work is needed.

---
*Prepared for a FAANG‑style interview – feel free to adapt the explanations to your personal style.*
