# Products of Array Except Self

## Problem Statement
Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.  
The algorithm must run in **O(n)** time and **without using division**.

### Core Challenges
- Achieving O(n) without division.
- Handling zeros in the input.
- Reducing auxiliary space to O(1) (excluding the output array).

## Approaches

### 1. Brute‑Force (O(n²) time, O(1) extra space)
For each index `i` iterate over the whole array and multiply every element except `i`.

**Complexities**
- Time: `O(n²)`
- Space: `O(1)` (output array not counted)

### 2. Prefix & Suffix Arrays (O(n) time, O(n) space)
- Build a `prefix[i]` = product of all elements before `i`.
- Build a `suffix[i]` = product of all elements after `i`.
- `answer[i] = prefix[i] * suffix[i]`.

**Complexities**
- Time: `O(n)`
- Space: `O(n)` for the two auxiliary arrays.

### 3. Optimal O(1) Extra Space (O(n) time, O(1) space)
- First pass: fill `answer[i]` with the prefix product.
- Second pass (right‑to‑left): keep a running suffix product and multiply it into `answer[i]`.

**Complexities**
- Time: `O(n)`
- Space: `O(1)` extra (output array is required by the problem).

## Interview Narrative – From Brute Force to Optimal
1. **Start with the obvious** – O(n²) nested loops. Shows you understand the problem.
2. **Ask about constraints** – “Can we use division?” – Usually *no*, which pushes you to think of prefix products.
3. **Introduce extra arrays** – Explain prefix & suffix, reducing time to O(n) but using O(n) space.
4. **Optimize space** – Point out that the output array can hold the prefix products, and a single variable can hold the suffix product during the second pass.

## Edge Cases Interviewers Love
| Input | Reason |
|-------|--------|
| `[0,0,2,3]` | Multiple zeros – every answer is `0`. |
| `[0,1,2,3]` | Single zero – only the position of the zero gets the product of the rest. |
| `[1]` (or length < 2) | Problem guarantees at least two elements, but discuss handling it gracefully. |
| Large numbers causing overflow | Use 64‑bit intermediate multiplication or note that LeetCode uses 32‑bit int with overflow wrap‑around. |

## Mock Interview Follow‑up Q&A

**Q1:** *Can we solve it using division?*  
**A:** Yes, if division were allowed we could compute the total product and divide by `nums[i]`. However, division is disallowed because of zeros and because the problem explicitly forbids it.

**Q2:** *How would you handle an input that contains zeros?*  
**A:** The optimal O(1) space solution naturally handles zeros: the prefix product up to the zero becomes `0`, and the suffix pass propagates the correct values. With a single zero, only the index of the zero receives the product of all non‑zero elements; with more than one zero, every entry is `0`.

**Q3:** *Can we improve the constant factor?*  
**A:** Yes – we can avoid the extra `suffix` array and reuse the output array, as shown in the optimal solution. Also, we can reserve the output vector size once to avoid reallocations.

**Q4:** *What if the array is extremely large and we cannot store the whole output in memory?*  
**A:** In that case we would need a streaming solution or chunked processing, but that goes beyond the constraints of the LeetCode problem.

---

Feel free to copy the implementations below into your IDE and run the provided test harness.
