# Largest Rectangle in Histogram

## Problem Statement
Given an array `heights` where `heights[i]` represents the height of a bar in a histogram (width of each bar is 1), find the area of the largest rectangle that can be formed within the bounds of the histogram.

### Core Challenges
* The rectangle can span multiple bars, so we need to consider the *minimum* height among a contiguous sub‑array.
* A naïve solution checks every possible sub‑array – O(n²) – which is too slow for large inputs (n can be up to 10⁵ on LeetCode).
* The key insight is that for each bar we want to know the farthest left and right positions where the bar is still the *shortest* bar. This can be obtained efficiently with a monotonic stack.

---

## Approaches

### 1️⃣ Brute‑Force (O(n²) time, O(1) extra space)
For every start index `i`, expand the end index `j` while keeping track of the minimum height seen so far. The area for `[i, j]` is `minHeight * (j‑i+1)`. Keep the maximum.

**Pros**: Simple, easy to explain.
**Cons**: Quadratic time – will TLE on large test cases.

### 2️⃣ Pre‑computed Limits (O(n) time, O(n) space)
* Compute `left[i]` – the first index to the left of `i` where height < `heights[i]` (exclusive). Use a monotonic increasing stack.
* Compute `right[i]` – the first index to the right of `i` where height < `heights[i]`.
* The maximal rectangle with height `heights[i]` spans from `left[i]` to `right[i]`, giving area `heights[i] * (right[i] - left[i] + 1)`.

**Pros**: Linear time, conceptually separates the two passes.
**Cons**: Requires two extra O(n) arrays.

### 3️⃣ Optimal Single‑Pass Stack (O(n) time, O(n) space)
Iterate through the histogram once, pushing indices onto a stack that maintains **increasing** heights. When a lower height is encountered, pop the stack – the popped index is the height of a rectangle whose right boundary is the current index. The left boundary is the new stack top + 1 (or 0 if the stack is empty). Append a sentinel height `0` at the end to flush remaining bars.

**Pros**: Linear time, only O(n) auxiliary space (the stack). This is the classic optimal solution.
**Cons**: Slightly trickier to explain on the spot; requires careful handling of indices.

---

## Complexity Summary
| Approach | Time | Extra Space |
|----------|------|-------------|
| Brute‑Force | O(n²) | O(1) |
| Pre‑computed Limits | O(n) | O(n) |
| Optimal Single‑Pass | O(n) | O(n) |

---

## Interview Narrative: From Brute‑Force to Optimal
1. **Start with the brute‑force** – show you understand the problem and can produce a correct solution.
2. **Identify the bottleneck** – the inner loop recomputes the minimum height for overlapping sub‑arrays.
3. **Introduce the “nearest smaller element” idea** – for each bar we only need the first smaller bar on each side.
4. **Show the two‑pass version** – compute left/right limits with a monotonic stack; this demonstrates you know the stack technique.
5. **Refine to the single‑pass** – explain that while computing the right limit we can simultaneously calculate the area, eliminating the extra arrays.
6. **Add a sentinel** – guarantees the stack empties at the end, simplifying code.
7. **Conclude with complexity** – O(n) time, O(n) space, which is optimal.

---

## Edge Cases Interviewers Love
| Edge Case | Why it’s tricky |
|-----------|-----------------|
| Empty array (`[]`) | Should return `0` – guard against out‑of‑bounds. |
| All bars equal | The optimal rectangle spans the whole array; ensure the algorithm doesn’t miss the final flush. |
| Strictly increasing heights | Right limits are at the end; the sentinel is essential. |
| Strictly decreasing heights | Left limits are at the start; stack will pop each bar immediately. |
| Single bar | Area equals its height. |
| Very large heights (up to 10⁹) | Use `long long` in C++ or `long` in Java if you multiply height * width (though LeetCode constraints fit in 32‑bit). |

---

## Mock Interview Follow‑up Q&A
1. **Q:** *Can we solve this without extra space?*  
   **A:** The optimal algorithm needs a stack to keep track of indices; this is O(n) auxiliary space. There is no known O(1) extra‑space solution that runs in linear time because we need to remember previous bars to compute widths.
2. **Q:** *What if the width of each bar isn’t 1?*  
   **A:** Store the actual widths in an auxiliary array and adjust the width calculation to sum those widths between the left and right boundaries.
3. **Q:** *How would you adapt the solution for a 2‑D matrix of heights (max rectangle of 1’s)?*  
   **A:** Treat each row as the base of a histogram, accumulate heights of consecutive 1’s column‑wise, and run the histogram algorithm on each row – O(m·n) overall.
4. **Q:** *Can we parallelize this algorithm?*  
   **A:** The stack‑based scan is inherently sequential because each step depends on the previous stack state. However, the two‑pass version can compute left and right limits in parallel if you use a divide‑and‑conquer approach, though the constant factor may outweigh benefits.

---

**Happy coding!**
