# Trapping Rain Water

## Problem Statement
Given an integer array `height` where `height[i]` represents the elevation map at index `i`, compute how much water it can trap after raining. The water trapped at each index is determined by the minimum of the highest bar on its left and the highest bar on its right, minus its own height.

**Example**
```
Input:  height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```

## Core Challenges
1. **Understanding the water level** – water at a position depends on the *global* maximum to its left and right, not just immediate neighbours.
2. **Balancing time vs. space** – a naïve solution scans left and right for every index (O(n²)). Interviewers expect you to recognise that pre‑computing or using two pointers can bring it down to linear time.
3. **Edge‑case awareness** – flat surfaces, monotonic increasing/decreasing arrays, and empty inputs must be handled gracefully.

## Approaches
### 1️⃣ Brute‑Force (O(n²) time, O(1) extra space)
For each index `i`:
* Scan all elements left of `i` to find `leftMax`.
* Scan all elements right of `i` to find `rightMax`.
* Water at `i` = `min(leftMax, rightMax) - height[i]` (if positive).

**Pros**: Simple, demonstrates baseline thinking.
**Cons**: Too slow for large inputs; interviewers will push you for a faster solution.

### 2️⃣ Prefix‑Suffix Max (O(n) time, O(n) space)
* Build `leftMax[i]` – the maximum height from start up to `i`.
* Build `rightMax[i]` – the maximum height from end down to `i`.
* One final pass computes trapped water using the pre‑computed arrays.

**Pros**: Linear time, easy to explain; shows you can trade space for speed.
**Cons**: Uses extra O(n) space – can be improved.

### 3️⃣ Two‑Pointer Optimal (O(n) time, O(1) space)
Maintain two pointers `left` and `right` and two variables `leftMax` and `rightMax`.
* Move the pointer with the smaller height inward.
* If the current height is lower than its side's max, water is trapped; otherwise update the side's max.
* Continue until pointers meet.

**Why it works**: The trapped water at the smaller side is bounded by the larger side's max, so we can safely compute it without looking ahead.

**Pros**: Best possible complexity; interviewers love this as the “aha!” moment.
**Cons**: Slightly trickier to articulate; practice the invariant explanation.

## Transition Explanation (Brute‑Force → Optimal)
1. **Identify the bottleneck** – the repeated left/right scans cause O(n²).
2. **Introduce memoisation** – store left/right maxima in arrays → O(n) time, O(n) space.
3. **Observe the invariant** – while scanning from both ends, the smaller side’s max is the limiting factor. This lets us discard the arrays and keep only two running maxima, achieving O(1) extra space.
4. **Summarise** – you moved from “re‑computing” to “re‑using” information, first via explicit storage, then via on‑the‑fly pointers.

## Edge Cases Interviewers Love
| Input | Reason it’s tricky |
|-------|--------------------|
| `[]` or `[0]` | No bars – answer 0.
| Monotonically increasing `[1,2,3,4]` | No left wall for later bars → 0.
| Monotonically decreasing `[4,3,2,1]` | No right wall for earlier bars → 0.
| All same height `[5,5,5,5]` | Flat surface – 0.
| Large plateau with a dip `[5,5,1,5,5]` | Water only over the dip – tests correct min‑max handling.
| Single high bar surrounded by zeros `[0,0,5,0,0]` | Water only on sides, not on the peak.

## Mock Interview Follow‑up Q&A
**Q1:** *Can we solve this problem without extra space if the input is read‑only?*  
**A:** Yes, the two‑pointer technique works in‑place because it only needs two indices and two scalar maxima – no modification of the original array.

**Q2:** *How would you adapt the solution for a 2‑D elevation map?*  
**A:** The 2‑D version (Trapping Rain Water II) requires a priority queue (min‑heap) to process the boundary cells first, expanding inward while maintaining the current water level – similar to Dijkstra’s algorithm.

**Q3:** *What if the heights can be negative?*  
**A:** Negative heights break the physical interpretation. If allowed, we can offset all values by the minimum height to make them non‑negative, then apply the same algorithm.

**Q4:** *Can you prove the two‑pointer algorithm is correct?*  
**A:** The invariant is: at any step, all positions left of `left` and right of `right` have been processed, and `leftMax` (`rightMax`) is the maximum height seen so far on the left (right) side. Because we always move the smaller side, the water trapped at that side is bounded by the larger side’s max, which is already known, guaranteeing correctness.

---
*Prepared for a FAANG interview – practice explaining each step clearly and be ready to discuss trade‑offs!*
