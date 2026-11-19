# Permutations – Backtracking Deep Dive

## Problem Statement
Given an array of **distinct** integers `nums`, return **all possible permutations** of the array. The order of the permutations does not matter.

**Example**
```text
Input:  nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

## Core Challenges
1. **Exponential Search Space** – There are `n!` permutations for `n` elements, so any solution must enumerate them.
2. **Avoid Duplicates** – Since the input guarantees distinct values, we only need to ensure we don’t revisit the same index in a single branch.
3. **Space Management** – Storing intermediate state (current path, visited flags, or in‑place swaps) impacts both readability and memory usage.
4. **Interview Communication** – Demonstrating a clear progression from a naïve solution to a clean, optimal one shows depth of understanding.

---

## Approach 1 – Brute‑Force Backtracking (with auxiliary `used` array)
### Idea
Recursively build a permutation by picking any unused element, marking it as used, and back‑tracking when the branch finishes.

### Pseudocode
```
backtrack(path, used):
    if path.size == n:
        add copy of path to answer
        return
    for i in 0..n-1:
        if used[i] continue
        used[i] = true
        path.append(nums[i])
        backtrack(path, used)
        path.pop()
        used[i] = false
```

### Complexity
*Time*: `O(n! * n)` – we generate `n!` permutations and copy `n` elements for each leaf.
*Space*: `O(n)` for the recursion stack + `O(n)` for the `used` array + output size.

### When to Use in an Interview
Start with this to prove you understand the exhaustive nature of the problem. It’s easy to explain and code, but you’ll soon discuss its inefficiencies (extra `used` array, copying the path each call).

---

## Approach 2 – In‑Place Swapping Backtracking (Intermediate Optimization)
### Idea
Instead of a separate `used` array, we fix the element at the current index by swapping it with every candidate that comes after it. This modifies the original array in‑place and restores it after the recursive call.

### Pseudocode
```
backtrack(first):
    if first == n:
        add copy of nums to answer
        return
    for i in first..n-1:
        swap(nums[first], nums[i])
        backtrack(first+1)
        swap(nums[first], nums[i])   // backtrack
```

### Complexity
*Time*: `O(n! * n)` – same asymptotic bound, but we avoid the extra `used` array and reduce constant factors.
*Space*: `O(1)` extra (ignoring recursion stack and output) because we reuse the input array.

### Interview Narrative
Explain that the `used` array is essentially a bookkeeping layer that can be eliminated by re‑ordering the array itself. This shows you can think about **state compression**.

---

## Approach 3 – Lexicographic Generation with `next_permutation` (Optimal / Iterative)
### Idea
If the input is sorted, the C++ STL (or a hand‑rolled `nextPermutation` in Java) can generate the next lexicographic permutation in `O(n)` time. Repeating this until we wrap around yields all `n!` permutations without recursion.

### Pseudocode (C++)
```
sort(nums)
do:
    add copy of nums to answer
while (next_permutation(nums))
```

### Pseudocode (Java – custom `nextPermutation`)
```
Arrays.sort(nums)
do:
    add copy of nums to answer
while (nextPermutation(nums))
```

### Complexity
*Time*: `O(n! * n)` – each call to `next_permutation` is `O(n)` and we call it `n!` times.
*Space*: `O(1)` extra (again ignoring output).

### Why This Is “Optimal”
* No recursion → no stack overhead.
* Constant auxiliary memory.
* Leverages a well‑tested library routine (or a short, interview‑friendly implementation).

---

## Transitioning From Brute‑Force to Optimal in an Interview
1. **Start with the obvious recursive solution** (Approach 1). Show you can enumerate all possibilities.
2. **Identify the overhead** – the `used` array and repeated copying of the path.
3. **Propose state compression** – swapping in‑place (Approach 2). Highlight that we’re still using backtracking but with `O(1)` extra space.
4. **Ask the interviewer if they care about recursion depth**. If they prefer an iterative solution, introduce the lexicographic `next_permutation` method (Approach 3).
5. **Discuss trade‑offs** – recursion is easier to reason about; the iterative method is marginally faster and uses less stack space.

---

## Edge Cases Interviewers Love to Test
| Edge case | Why it matters |
|-----------|----------------|
| `nums` is empty (`[]`) | Should return an empty list `[]` (or `[[]]` depending on definition). Our implementations return an empty vector/list because the base case never fires. |
| Single element `[5]` | Guarantees the algorithm handles the minimal non‑trivial case. |
| Already sorted vs. reverse sorted input | For the iterative `next_permutation` approach, starting from a reverse‑sorted array should still produce all permutations after the initial sort. |
| Large `n` (e.g., `n = 8`) | Confirms the algorithm scales to the factorial blow‑up and that you’re not using exponential‑time sub‑routines beyond the inevitable `n!`. |

---

## Mock Interview Follow‑up Q&A
1. **Q:** *Can we generate permutations in lexicographic order without sorting first?*  
   **A:** Yes, if the input is already in the desired start order. Otherwise we sort to guarantee the first permutation is the smallest lexicographically.
2. **Q:** *How would you modify the algorithm to handle duplicate numbers?*  
   **A:** Use a `Set` (or skip‑duplicate logic) at each recursion level: sort the array first, then skip `i` when `i > first && nums[i] == nums[i‑1]`.
3. **Q:** *What is the memory impact of storing all permutations for `n = 10`?*  
   **A:** There are `10! = 3,628,800` permutations. Each permutation stores `10` integers → roughly 144 MB of raw integer data, plus overhead for containers, which is why we usually discuss the output size as part of the complexity.
4. **Q:** *Is there a way to generate the *k‑th* permutation directly?*  
   **A:** Yes, using factorial number system (LeetCode 60). It avoids generating all permutations and runs in `O(n)` time.

---

## TL;DR
* **Brute‑Force** – simple backtracking with a `used` array (`O(n!·n)` time, `O(n)` extra space).
* **Better** – in‑place swapping backtracking (`O(n!·n)` time, `O(1)` extra space).
* **Optimal** – iterative `next_permutation` (`O(n!·n)` time, `O(1)` extra space, no recursion).

Use the progression to demonstrate problem‑solving depth, state compression, and awareness of library utilities.
