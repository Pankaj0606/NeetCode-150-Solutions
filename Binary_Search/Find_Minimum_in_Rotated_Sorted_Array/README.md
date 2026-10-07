# Find Minimum in Rotated Sorted Array

## Problem Statement
Given an integer array `nums` sorted in ascending order, it is rotated at an unknown pivot index `k` (`0 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`. All elements are **unique**. Return the minimum element of this array.

### Core Challenges
1. **Rotation hides the true start** – the smallest element could be anywhere.
2. **No duplicate values** simplifies the binary‑search decision making.
3. **Time‑critical interview** – you need to show you can improve from O(n) to O(log n).

---

## Approaches
### 1️⃣ Brute‑Force (Linear Scan)
```cpp
int findMin(vector<int>& nums) {
    int ans = nums[0];
    for (int v : nums) ans = min(ans, v);
    return ans;
}
```
* **Time:** O(n) – we look at every element.
* **Space:** O(1).

### 2️⃣ Better – Classic Binary Search (Iterative)
We exploit the fact that at least one half of the array is sorted.
```cpp
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r]) {
            // min is in the right half
            l = mid + 1;
        } else {
            // min is in the left half (including mid)
            r = mid;
        }
    }
    return nums[l];
}
```
* **Time:** O(log n).
* **Space:** O(1).
* This is already optimal for the problem, but we call it *better* because it introduces the binary‑search pattern without extra tricks.

### 3️⃣ Optimal – Binary Search with Early‑Exit Check
If the sub‑array `[l, r]` is already sorted (`nums[l] < nums[r]`), the leftmost element is the answer. Adding this check can cut the number of iterations roughly in half for already‑sorted inputs.
```cpp
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        if (nums[l] < nums[r]) return nums[l]; // early exit
        int mid = l + (r - l) / 2;
        if (nums[mid] >= nums[l]) {
            // left part is sorted, min must be right of mid
            l = mid + 1;
        } else {
            // right part is unsorted, min is at mid or left of it
            r = mid;
        }
    }
    return nums[l];
}
```
* **Time:** O(log n) – same asymptotic bound, but constant factor improves for many cases.
* **Space:** O(1).

---

## Interview Narrative: From Brute‑Force to Optimal
1. **Start with the obvious** – linear scan. Shows you understand the problem and can produce a correct solution quickly.
2. **Ask the interviewer**: *“Can we do better than O(n)?”* If yes, point out the array is *almost* sorted; only a rotation breaks the order.
3. **Introduce binary search** – explain that at any point one half is sorted, so the minimum must lie in the unsorted half.
4. **Refine** – add the early‑exit condition (`nums[l] < nums[r]`) to handle already‑sorted sub‑arrays, demonstrating attention to constant‑factor optimization.
5. **Complexity recap** – each step reduces the search space by half → O(log n) time, O(1) space.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters | Expected handling |
|-----------|----------------|-------------------|
| Single element `[1]` | Smallest possible input | Return the element itself |
| Already sorted (no rotation) `[1,2,3,4,5]` | Early‑exit path should trigger | Return first element |
| Rotation at last index `[2,3,4,5,1]` | Minimum is at the end of the original array | Binary search correctly moves `r` left |
| Large array (10⁵+ elements) | Tests O(log n) vs O(n) performance | Must finish quickly |

---

## Mock Interview Follow‑up Q&As
**Q1:** *What if duplicates are allowed?*  
**A:** The `nums[mid] == nums[r]` case becomes ambiguous. We fall back to `r--` (or `l++`) to shrink the window, degrading worst‑case to O(n).

**Q2:** *Can we solve it without extra variables?*  
**A:** Yes – the optimal solution already uses only two indices (`l` and `r`). No auxiliary containers are needed.

**Q3:** *How would you find the rotation index instead of the minimum?*  
**A:** The rotation index is exactly the position of the minimum. Return `l` (or `r`) after the binary search finishes.

**Q4:** *Is there a way to make it recursive?*  
**A:** Absolutely. A recursive helper that takes `l` and `r` and applies the same logic works, but it adds O(log n) call‑stack space.

---

## TL;DR
* **Brute‑Force:** Scan → O(n).
* **Better:** Classic binary search → O(log n).
* **Optimal:** Binary search with early‑exit → O(log n) with better constants.
* Know the edge cases, be ready to discuss duplicates, and you’ll impress any interviewer.
