# Best Time to Buy and Sell Stock

## Problem Statement
Given an array `prices` where `prices[i]` is the price of a given stock on day `i`, you may complete **at most one** transaction (i.e., buy one and sell one share). Return the maximum profit you can achieve. If no profit can be made, return `0`.

## Core Challenges
- Identify that the profit is `prices[j] - prices[i]` with the constraint `i < j`.
- Need to handle large input sizes efficiently (linear time preferred).
- Correctly handle edge cases such as an empty array, a single price, or a monotonically decreasing price list.

## Approaches

### 1️⃣ Brute‑Force (Worst) – **O(n²) time, O(1) space**
Enumerate every possible pair of buy‑day and sell‑day and keep the maximum profit.
```text
for i from 0 to n‑1:
    for j from i+1 to n‑1:
        profit = prices[j] - prices[i]
        update answer
```
*Pros*: Simple, easy to explain.
*Cons*: Too slow for `n` up to 10⁵ (typical LeetCode constraints).

### 2️⃣ Prefix‑Min (Better) – **O(n) time, O(n) space**
Pre‑compute the minimum price seen up to each index.
```text
minPrice[0] = prices[0]
for i = 1 .. n‑1:
    minPrice[i] = min(minPrice[i‑1], prices[i])

maxProfit = 0
for i = 1 .. n‑1:
    maxProfit = max(maxProfit, prices[i] - minPrice[i‑1])
```
*Pros*: Linear time, clear separation of "what is the best buy price so far" and "what profit can we get today".
*Cons*: Uses extra O(n) auxiliary array.

### 3️⃣ One‑Pass (Optimal) – **O(n) time, O(1) space**
Maintain two variables while scanning the array once:
- `minPriceSoFar` – the smallest price encountered.
- `maxProfit` – the best profit achievable up to the current day.
```text
minPriceSoFar = +∞
maxProfit = 0
for price in prices:
    if price < minPriceSoFar:
        minPriceSoFar = price
    else:
        maxProfit = max(maxProfit, price - minPriceSoFar)
```
*Pros*: Optimal in both time and space, the pattern appears in many "maximum sub‑array" style problems.
*Cons*: Slightly more mental overhead for beginners, but easy to convey.

## Complexity Summary
| Approach | Time | Space |
|----------|------|-------|
| Brute‑Force | O(n²) | O(1) |
| Prefix‑Min | O(n) | O(n) |
| One‑Pass (Optimal) | O(n) | O(1) |

## How to Transition During an Interview
1. **Start with Brute‑Force** – Show the naïve double loop, discuss its correctness, then point out the quadratic runtime.
2. **Ask the Interviewer About Patterns** – “Can we reuse information from previous days?” This nudges toward a *prefix* idea.
3. **Introduce Prefix‑Min** – Explain that the best buy price up to day `i` is the minimum of all previous prices. Show the two‑pass solution and its linear runtime.
4. **Push Further** – “Do we really need the whole `minPrice` array?” Realise we only need the most recent minimum, leading to the one‑pass solution with O(1) extra space.
5. **Summarize** – Highlight that the optimal solution is essentially Kadane’s algorithm on the price‑difference array.

## Edge Cases Interviewers Love
- `prices = []` or a single element → profit `0`.
- Strictly decreasing prices, e.g., `[9,7,4,1]` → profit `0`.
- Large numbers near integer limits – use `long long`/`int` safely (LeetCode uses `int`).
- Repeated equal prices, e.g., `[5,5,5,5]` → profit `0`.

## Mock Interview Follow‑up Q&As
**Q1:** *Can we extend this to multiple transactions?*  
**A:** Yes. The problem becomes “Best Time to Buy and Sell Stock II”. The optimal solution sums all positive consecutive differences, or uses DP with `hold`/`cash` states.

**Q2:** *What if there is a transaction fee for each sell?*  
**A:** Introduce a fee variable `fee`. In the one‑pass DP, update `maxProfit = max(maxProfit, price - minPriceSoFar - fee)` and adjust `minPriceSoFar` accordingly.

**Q3:** *How would you solve it if you could short‑sell (sell before you buy)?*  
**A:** The profit becomes `max(prices[i] - minPriceSoFar, maxPriceSoFar - prices[i])`. You would track both min and max seen so far and take the larger absolute difference.

**Q4:** *Can you prove that the one‑pass algorithm is optimal?*  
**A:** By induction: after processing day `i`, `minPriceSoFar` is the minimum of `prices[0..i]`. Any future profit must subtract a price that occurred earlier, so the best profit ending at day `i` is `prices[i] - minPriceSoFar`. Keeping the maximum of these values yields the global optimum.
