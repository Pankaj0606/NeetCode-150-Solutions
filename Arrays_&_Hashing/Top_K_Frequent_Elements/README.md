# Top K Frequent Elements

## Problem Statement
Given an integer array `nums` and an integer `k`, return the `k` most frequent elements in **any order**.

### Core Challenges
* Efficiently count frequencies of elements.
* Retrieve the top‑`k` frequencies without sorting the entire dataset when possible.
* Handle edge cases such as `k` equal to the number of unique elements, negative numbers, and large input sizes.

---

## Approaches
### 1️⃣ Brute‑Force (Worst Case)
* **Idea**: Count frequencies with a hash map. Then repeat `k` times: scan the map to find the current maximum frequency, add that element to the result, and remove it from the map.
* **Time Complexity**: `O(N * K)` – each scan over the map costs `O(U)` where `U` is the number of unique elements (≤ `N`). In the worst case `U ≈ N`.
* **Space Complexity**: `O(U)` for the frequency map and result container.

### 2️⃣ Better / Intermediate Optimization
* **Idea**: Count frequencies, then sort the `(frequency, element)` pairs in descending order and pick the first `k` elements.
* **Time Complexity**: `O(N + U log U)` – counting is linear, sorting dominates.
* **Space Complexity**: `O(U)` for the map and the vector of pairs.

### 3️⃣ Optimal Approach
* **Idea**: Use a **min‑heap** (priority queue) of size `k`. While iterating over the frequency map, push each `(freq, element)` pair onto the heap; if the heap exceeds size `k`, pop the smallest. At the end the heap contains the top `k` frequent elements.
* **Time Complexity**: `O(N + U log K)` – linear counting plus heap operations limited to `k`.
* **Space Complexity**: `O(U + K)` – map plus heap of size `k`.

---

## Interview Narrative: From Brute‑Force to Optimal
1. **Start with the obvious** – a hash map for counting. This shows you understand basic frequency counting.
2. **Identify the bottleneck** – repeatedly scanning the map is `O(N*K)`. Mention that sorting all frequencies would improve it to `O(N log N)`.
3. **Propose a heap** – explain that we only need the top `k`, so a min‑heap of size `k` keeps the work to `log K` per element.
4. **Optional discussion** – talk about bucket sort (`O(N)`) when the range of frequencies is bounded, or quick‑select for average‑case linear time.
5. **Conclude** – the heap solution is the most common interview answer because it balances simplicity and optimality.

---

## Edge Cases Interviewers Love
| Case | Why it matters |
|------|----------------|
| `k == number of unique elements` | Result should be all distinct numbers; heap should still work.
| All elements are the same | Frequency map size = 1; heap operations trivial.
| Large `nums` with many duplicates | Tests both time and space efficiency.
| Negative numbers or zeros | Confirms you treat values as keys, not indices.
| `k == 0` (though LeetCode guarantees `k ≥ 1`) | Good to mention defensive handling.

---

## Mock Interview Follow‑up Q&A
**Q1:** *Can we achieve `O(N)` time without extra space?*  
**A:** Yes, using **bucket sort** because frequencies range from `1` to `N`. Create an array of buckets where index = frequency, then iterate from high to low collecting elements until `k` are gathered. This is linear time and `O(N)` extra space.

**Q2:** *What if the input array is already sorted by frequency?*  
**A:** The heap solution still works, but we could simply take the first `k` elements. Detecting this special case isn’t required unless explicitly asked.

**Q3:** *How would you modify the solution to return the elements sorted by decreasing frequency?*  
**A:** After extracting from the heap, sort the result based on the original frequencies, or use a max‑heap instead of a min‑heap.

**Q4:** *Explain the trade‑off between the heap and quick‑select approaches.*  
**A:** Heap guarantees `O(N log K)` worst‑case time and is easy to code. Quick‑select gives average `O(N)` but worst‑case `O(N^2)` unless randomized; it also requires an extra array of pairs.

---

## Summary
* **Brute‑Force:** Simple map + repeated max scan – easy to explain but inefficient.
* **Better:** Map + sort – `O(N log N)` and often acceptable.
* **Optimal:** Map + min‑heap of size `k` – `O(N log K)` and the go‑to solution in interviews.

Happy coding!
