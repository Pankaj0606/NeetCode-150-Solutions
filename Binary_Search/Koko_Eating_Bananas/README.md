# Koko Eating Bananas – Interview Guide

## Problem Statement
Koko loves to eat bananas. There are `n` piles of bananas, where `piles[i]` is the number of bananas in the *i‑th* pile.

Koko can decide on an integer eating speed `K` (bananas per hour). Every hour she chooses **one** pile and eats `K` bananas from it. If the pile has fewer than `K` bananas, she finishes the pile and the hour ends.

Given the array `piles` and an integer `H` (the number of hours Koko has to finish all bananas), return the **minimum** integer `K` such that she can eat all the bananas within `H` hours.

### Core Challenges
1. **Monotonicity** – If a speed `K` works, any speed `>= K` also works. This enables binary search.
2. **Large Search Space** – `K` can be as large as `max(piles)` (up to 10⁹ in the original LeetCode constraints). A naïve linear scan is too slow.
3. **Time‑per‑Pile Calculation** – For a given `K`, the hours needed for a pile `p` is `ceil(p / K) = (p + K - 1) / K`. Doing this efficiently is key.
4. **Edge Cases** – Very small `H` (e.g., `H == piles.length`) forces `K = max(piles)`. Very large `H` (e.g., `H >= sum(piles)`) forces `K = 1`.

---

## Approaches

### 1️⃣ Brute‑Force (Linear Scan)
**Idea** – Try every possible speed `K` from `1` to `max(piles)` and simulate the eating process.

**Algorithm**
```text
maxPile = max(piles)
for K = 1 .. maxPile:
    hours = 0
    for each pile p:
        hours += ceil(p / K)
    if hours <= H: return K
return maxPile
```

**Complexity**
- Time: `O(maxPile * n)` – infeasible when `maxPile` is large (up to 10⁹).
- Space: `O(1)`.

**When to use in interview** – Mention it first to show you understand the problem, then explain why it’s too slow and motivate a better solution.

---

### 2️⃣ Better / Intermediate Optimization (Binary Search – Classic)
**Idea** – Because feasibility is monotonic, binary search the answer between `1` and `max(piles)`.

**Algorithm**
```text
lo = 1, hi = max(piles)
while lo < hi:
    mid = (lo + hi) / 2
    if canFinish(mid): hi = mid
    else               lo = mid + 1
return lo
```
`canFinish(K)` computes the total hours using the formula `(p + K - 1) / K` and aborts early if the sum exceeds `H`.

**Complexity**
- Time: `O(n * log(maxPile))` – fast enough for the constraints.
- Space: `O(1)`.

**Interview tip** – Emphasize the early‑break optimization; it prevents unnecessary work when `mid` is too small.

---

### 3️⃣ Optimal Approach (Tightened Search Bounds)
**Idea** – The lower bound can be improved from `1` to `ceil(totalBananas / H)`. No speed smaller than this can possibly finish in `H` hours because even if Koko ate from *all* piles simultaneously, she would need at least that many bananas per hour.

**Algorithm**
```text
total = sum(piles)
maxPile = max(piles)
lo = max(1, ceil(total / H))
hi = maxPile
binary search exactly as in the intermediate solution
```
All other details stay the same (early break, integer arithmetic).

**Complexity**
- Time: `O(n * log(maxPile - lo + 1))` – marginally better constant factor.
- Space: `O(1)`.

**Why it’s optimal** – It uses the smallest possible search interval and the same linear‑time feasibility check, which is the lower bound for this problem class.

---

## Transition Narrative (Brute → Optimal) for an Interview
1. **Start with brute force** – Show you can write a correct solution.
2. **Identify the bottleneck** – The loop over all possible `K` is huge.
3. **Spot monotonicity** – If a speed works, any larger speed works → binary search.
4. **Implement binary search** – Explain the `canFinish` helper and early exit.
5. **Tighten bounds** – Derive a realistic lower bound using total bananas; this demonstrates deeper analytical thinking.
6. **Conclude** – The final code runs in `O(n log max)` with `O(1)` extra space, which is optimal for this problem.

---

## Edge Cases Interviewers Love
| Situation | Reason it’s tricky | Expected handling |
|-----------|--------------------|-------------------|
| `H == piles.size()` | Koko has exactly one hour per pile → must eat the biggest pile in one hour. | Return `max(piles)`.
| `H >= sum(piles)` | Plenty of time – the answer is `1`. | Lower bound calculation yields `1`.
| Single pile, huge `H` | Same as above but with only one element. | Works with any approach.
| All piles equal | Binary search still works; early break never triggers. | No special code needed.
| Large numbers (up to 10⁹) | Risk of integer overflow when summing hours. | Use `long long` / `long` for the hour accumulator.

---

## Mock Interview Follow‑up Q&A
1. **Q:** *Can we solve this without binary search?*  
   **A:** Yes, you could use a priority queue to always eat from the largest pile, but that leads to `O(H log n)` which is worse when `H` is large. Binary search gives the proven optimal `O(n log max)`.
2. **Q:** *Why do we use `(p + K - 1) / K` instead of `Math.ceil(p / K)`?*  
   **A:** Integer arithmetic avoids floating‑point errors and is O(1). The expression is mathematically equivalent to the ceiling.
3. **Q:** *What if `H` is smaller than `piles.size()`?*  
   **A:** The problem guarantees a solution exists, which implies `H >= piles.size()`. If not, the answer would be impossible; we could return `-1` or throw.
4. **Q:** *How would you adapt the solution for a streaming input where piles are read one‑by‑one?*  
   **A:** You’d need to store the piles to evaluate feasibility multiple times, or you could perform a two‑pass approach: first compute `max` and `total`, then binary search while re‑reading the stream (if possible). Otherwise, you’d need extra memory to keep the array.
5. **Q:** *Can we parallelize the feasibility check?*  
   **A:** Yes, the sum of hours over piles is embarrassingly parallel; each thread can compute a partial sum and combine. The overall complexity stays the same, but wall‑clock time improves with multiple cores.

---

## Final Thoughts
The key to cracking this problem in an interview is to **show the progression of thought**: start simple, recognize monotonicity, apply binary search, then tighten the bounds. Mentioning early‑break optimizations and overflow safety demonstrates attention to detail that interviewers appreciate.

---

*Happy coding!*
