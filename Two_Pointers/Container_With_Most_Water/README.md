# Container With Most Water

## Problem Statement
Given an array `height` where `height[i]` represents the height of a vertical line drawn at coordinate `i`, find two lines that together with the x‑axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store.

Formally, for any pair of indices `i < j`, the amount of water is `min(height[i], height[j]) * (j - i)`. You must return the maximum value over all possible pairs.

## Core Challenges
1. **Brute‑force intuition** – checking every pair gives the correct answer but is too slow for large inputs.
2. **Identifying monotonicity** – moving the pointer that points to the shorter line can only improve (or keep) the answer because the height is the limiting factor.
3. **Balancing time vs. space** – some optimisations use extra data structures (e.g., sorting) to reduce time at the cost of additional space.

---

## Approaches
### 1️⃣ Brute Force (O(n²) time, O(1) space)
Iterate over all possible pairs `(i, j)` and compute the area. Keep the maximum.

**Pros**: Simple, easy to explain.
**Cons**: Quadratic time – will TLE for `n` up to 10⁵.

### 2️⃣ Intermediate Optimization – Sort by Height (O(n log n) time, O(n) space)
1. Pair each height with its index.
2. Sort the pairs in **descending** order of height.
3. While scanning the sorted list, maintain the smallest and largest index seen so far. For the current height `h`, the best width achievable with any previously seen taller line is `maxIdx - minIdx`. Compute `h * (maxIdx - minIdx)` and update the answer.

This works because any container formed with a shorter line cannot beat a container formed with a taller line and the same width.

**Pros**: Better than O(n²) and demonstrates a different line of thinking.
**Cons**: Still slower than the optimal linear solution and uses extra memory.

### 3️⃣ Optimal Two‑Pointer (O(n) time, O(1) space)
Place one pointer at the start (`left`) and one at the end (`right`).
- Compute the area with the current pair.
- Move the pointer that points to the **shorter** line inward, because the height limits the area; moving the taller line cannot increase the height and only reduces width.
- Repeat until the pointers meet.

This greedy strategy guarantees that every possible width is examined with the best possible height for that width.

**Pros**: Linear time, constant space – the best possible.
**Cons**: Requires a clear explanation of why moving the shorter line is safe.

---

## Transitioning in an Interview
1. **Start with brute force** – show you understand the definition of the problem.
2. **Identify the bottleneck** – O(n²) is too slow; point out the repeated work.
3. **Discuss observations** – the area is limited by the shorter line; moving the taller line never helps.
4. **Propose the two‑pointer idea** – explain the greedy move and why it cannot miss the optimal solution.
5. **If pressed for alternatives** – mention the sorting‑based O(n log n) method as a middle ground.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters |
|-----------|----------------|
| `height` length = 2 | Smallest valid input – algorithm must still work.
| All heights equal | Any pair yields the same area; ensures you aren't relying on strict > comparisons.
| Strictly increasing or decreasing heights | Tests pointer‑movement logic.
| Very large heights (up to 10⁴) and large `n` (up to 10⁵) | Checks for integer overflow – use `long long` in C++ if needed, but `int` suffices for LeetCode constraints.

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve this problem with DP?*  
**A:** Not naturally. The state depends on two indices, leading to O(n²) DP which offers no advantage over brute force.

**Q2:** *What if we need the indices of the lines, not just the area?*  
**A:** Store the pair when you update the maximum area in any approach; the two‑pointer method naturally gives you the current indices.

**Q3:** *How would the solution change if the container could be tilted?*  
**A:** The problem becomes a different geometry problem; the current monotonic‑height property no longer holds, so a new model is required.

**Q4:** *Is there a way to parallelise the brute‑force solution?*  
**A:** Yes, you could split the pair space across threads, but the overhead usually outweighs benefits for typical interview constraints.

---

## Summary
- Brute force: O(n²) – easy to write, not scalable.
- Sort‑by‑height: O(n log n) – demonstrates alternative thinking with extra space.
- Two‑pointer: O(n) time, O(1) space – the optimal, interview‑gold solution.

Implementations for C++ and Java are provided below.
