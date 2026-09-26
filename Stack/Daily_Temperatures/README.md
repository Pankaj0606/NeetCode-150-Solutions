# Daily Temperatures

## Problem Statement & Core Challenges
Given an array `temperatures` where `temperatures[i]` is the temperature on day `i`, return an array `answer` such that `answer[i]` is the number of days you have to wait after day `i` to get a warmer temperature. If there is no future day for which this is possible, put `0` instead.

**Core challenges**
- For each day we need to find the *next greater element* to the right.
- A naïve double‑loop works but is too slow for large inputs (`O(n²)`).
- The optimal solution relies on a **monotonic decreasing stack** (or a DP‑style skip‑ahead) to achieve linear time.

---

## Approaches
### 1️⃣ Brute‑Force (Worst)
```cpp
vector<int> ans(n,0);
for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
        if (T[j] > T[i]) { ans[i] = j - i; break; }
    }
}
```
*Time*: **O(n²)** – every pair may be examined.
*Space*: **O(1)** extra (output array excluded).

### 2️⃣ Better / Intermediate Optimization
We scan from right to left and **skip** over indices whose answer is already known. This is a DP‑style “jump‑ahead” technique.
```cpp
vector<int> ans(n,0);
for (int i = n - 2; i >= 0; --i) {
    int j = i + 1;
    while (j < n && T[j] <= T[i]) {
        if (ans[j] == 0) { j = n; break; } // no warmer day ahead
        j += ans[j]; // jump to the next candidate
    }
    if (j < n) ans[i] = j - i;
}
```
*Time*: **O(n)** amortized – each index is visited at most a few times.
*Space*: **O(1)** extra.

### 3️⃣ Optimal (Monotonic Stack)
Maintain a stack of indices with **strictly decreasing** temperatures. When a warmer day appears, pop all colder days and compute their answers.
```cpp
stack<int> st; // stores indices
for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && T[st.top()] <= T[i]) st.pop();
    if (!st.empty()) ans[i] = st.top() - i;
    st.push(i);
}
```
*Time*: **O(n)** – each index is pushed and popped at most once.
*Space*: **O(n)** in the worst case for the stack.

---

## Interview Narrative: From Brute‑Force to Optimal
1. **Start with the obvious** – explain the double loop, its simplicity, and its `O(n²)` cost.
2. **Identify the pattern** – we are repeatedly looking for the *next greater element* to the right.
3. **Introduce the “skip‑ahead” DP** – show how previously computed answers let us jump over blocks of days, reducing work.
4. **Present the monotonic stack** – the classic linear‑time solution for next‑greater‑element problems. Emphasize the invariant (stack is decreasing) and why each element is processed once.
5. **Compare complexities** and discuss trade‑offs (stack uses extra space but is clean and deterministic).

---

## Edge Cases Interviewers Love
| Input | Reason it’s tricky |
|-------|--------------------|
| `[]` or single element | Empty or trivial output – should return an empty vector/array. |
| All decreasing temperatures, e.g., `[90,80,70]` | No warmer day exists; every answer must be `0`. |
| All equal temperatures, e.g., `[70,70,70]` | Equality does **not** count as warmer; still all zeros. |
| Large plateau followed by a spike, e.g., `[70,70,70,71]` | Tests whether the algorithm correctly jumps over many equal/colder days. |
| Max input size (`10⁵`+) | Guarantees the solution is truly `O(n)` and not quadratic. |

---

## Mock Interview Follow‑up Q&As
**Q1.** *Can we solve this without extra space?*  
**A:** The DP “skip‑ahead” version uses only the output array, so it is `O(1)` auxiliary space. The stack version uses `O(n)` extra space but is often preferred for clarity.

**Q2.** *What if we needed the *previous* warmer day instead of the next?*  
**A:** Scan from left to right with a monotonic decreasing stack; the logic is symmetric.

**Q3.** *How would you adapt the solution for a circular array (wrap‑around)?*  
**A:** Iterate twice (i from `2n‑1` down to `0`) and use modulo indexing while keeping the same stack logic.

**Q4.** *Can we parallelize this problem?*  
**A:** The dependency on future values makes a straightforward parallel solution hard. However, divide‑and‑conquer with suffix‑max information can be explored, though it adds complexity.

---

**Bottom line:** Master the monotonic stack pattern – it appears in many “next greater element” problems and demonstrates a clean, linear‑time solution that interviewers love to see.
