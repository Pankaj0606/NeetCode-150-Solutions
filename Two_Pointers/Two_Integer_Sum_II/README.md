# Two Integer Sum II (LeetCode 167)

## Problem Statement & Core Challenges
Given a **1-indexed** array `numbers` that is **sorted in non‑decreasing order**, find the indices of the two numbers such that they add up to a specific `target`. Return the answer as a length‑2 array `[index1, index2]` where `index1 < index2`. The solution must use **O(1)** extra memory for the optimal approach.

**Core challenges**:
- Exploit the sorted property to improve over the naïve O(n²) solution.
- Keep track of 1‑based indexing required by the problem.
- Discuss trade‑offs between time and space while interviewing.

---

## Approaches
### 1️⃣ Brute Force (Worst / O(n²))
Iterate over every pair `(i, j)` with `i < j` and check if `numbers[i] + numbers[j] == target`. Return the first matching pair.

- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)

### 2️⃣ Better / Intermediate Optimization (Hash Map – O(n) time, O(n) space)
Even though the array is sorted, we can treat it like an unsorted array and store each element in a hash map while scanning. For each element `x`, we look for `target - x` in the map.

- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 3️⃣ Optimal (Two‑Pointer – O(n) time, O(1) space)
Because the array is sorted, maintain two pointers:
- `left` starts at the beginning.
- `right` starts at the end.
If the sum is too small, move `left` rightward; if too large, move `right` leftward. The first time the sum equals `target` we have the answer.

- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

---

## Interview Narrative: From Brute Force to Optimal
1. **Start with the obvious** – mention the double‑loop brute‑force solution. Show you understand correctness.
2. **Identify the bottleneck** – O(n²) is too slow for large inputs; ask the interviewer if extra space is allowed.
3. **Propose a hash‑map** – O(n) time, O(n) space. Explain how it works and its trade‑off.
4. **Leverage the sorted array** – point out that the problem explicitly gives a sorted array, which hints at a two‑pointer technique.
5. **Present the two‑pointer solution** – O(n) time, O(1) space, the best you can achieve. Walk through an example to prove correctness.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters | How each approach handles it |
|-----------|----------------|-----------------------------|
| Empty array or single element | No valid pair exists | All approaches return an empty vector/array |
| Multiple pairs sum to target | Must return *any* valid pair, but usually the first encountered | Brute‑force returns the first pair in lexicographic order; hash‑map returns the pair where the second index is the current iteration; two‑pointer returns the outermost pair (smallest left, largest right) which is deterministic |
| Large numbers causing overflow | Use `long long` in C++ or `long` in Java if needed | In these implementations we rely on `int` because LeetCode guarantees 32‑bit safe inputs, but mention the fix |
| Negative numbers (though LeetCode guarantees non‑negative) | Tests understanding of algorithmic assumptions | All three approaches still work; two‑pointer works because sorting still holds |

---

## Mock Interview Follow‑up Q&As
1. **Q:** *Can we solve the problem without using extra space and without the two‑pointer trick?*  
   **A:** Yes, we could use binary search for each element (`O(n log n)` time, `O(1)` space). It’s better than brute force but still not optimal compared to two‑pointers.
2. **Q:** *What if the array were **not** sorted?*  
   **A:** The two‑pointer technique would no longer be valid. The hash‑map solution (`O(n)` time, `O(n)` space) becomes the optimal choice.
3. **Q:** *How would you modify the solution to return **all** unique pairs?*  
   **A:** Use a two‑pointer loop, but after finding a valid pair, move both pointers past duplicates and continue scanning, collecting pairs in a list.
4. **Q:** *What is the impact of using `vector<int>` vs `int[]` for the return type in terms of performance?*  
   **A:** Negligible for this problem; both allocate a small constant‑size container. The important metric is algorithmic complexity, not container overhead.

---

## Summary
- Brute force is simple but inefficient.
- Hash‑map gives linear time at the cost of linear extra space.
- Two‑pointer exploits the sorted property for **optimal O(n) time, O(1) space**.
- Knowing when to transition between these approaches demonstrates strong problem‑solving and communication skills in an interview.
