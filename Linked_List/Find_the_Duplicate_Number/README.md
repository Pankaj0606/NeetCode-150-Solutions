# Find the Duplicate Number

## Problem Statement & Core Challenges
The input is an array `nums` of length `n + 1` where each integer is in the range `[1, n]`. Exactly **one** number appears **at least twice** (it may appear more than twice). Your task is to return **any** duplicate number.

Key challenges:
- The array is **read‑only** in the optimal solution – you cannot modify it.
- You must achieve **O(n)** time and **O(1)** extra space.
- Interviewers love to probe edge‑cases such as the duplicate being at the start, end, or appearing many times.

---

## Approaches
### 1️⃣ Brute‑Force (Quadratic Time)
```cpp
// C++
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) return nums[i];
            }
        }
        return -1; // never reached per problem constraints
    }
};
```
```java
// Java
class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) return nums[i];
            }
        }
        return -1;
    }
}
```
- **Time:** `O(n²)` – every pair is compared.
- **Space:** `O(1)`.
- **When to use:** Only to demonstrate the baseline or when `n` is tiny.

---

### 2️⃣ Better / Intermediate Optimization
Two common variants:
1. **Sorting** – `O(n log n)` time, `O(1)` (or `O(n)`) extra space if in‑place.
2. **Hash Set** – `O(n)` time, `O(n)` extra space.

We present the hash‑set version because it is simple and interview‑friendly.
```cpp
// C++ – Hash Set
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return num;
            seen.insert(num);
        }
        return -1;
    }
};
```
```java
// Java – Hash Set
import java.util.*;

class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (seen.contains(num)) return num;
            seen.add(num);
        }
        return -1;
    }
}
```
- **Time:** `O(n)`.
- **Space:** `O(n)` auxiliary.
- **When to use:** When you are allowed extra memory or want a quick, clean solution.

---

### 3️⃣ Best / Optimal – Floyd’s Tortoise & Hare (Cycle Detection)
Treat the array as a linked list where each index points to `nums[index]`. Because there are `n + 1` nodes but only `n` possible values, a cycle **must** exist, and the entry point of the cycle is the duplicate.
```cpp
// C++ – Floyd's Tortoise & Hare
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        // Phase 1: find intersection
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // Phase 2: find entrance to the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
```
```java
// Java – Floyd's Tortoise & Hare
class Solution {
    public int findDuplicate(int[] nums) {
        int slow = nums[0];
        int fast = nums[0];
        // Phase 1
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // Phase 2
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
}
```
- **Time:** `O(n)` – each pointer moves at most twice through the array.
- **Space:** `O(1)` – only a few integer variables.
- **Why it works:** The duplicate creates a “loop” in the functional graph; Floyd’s algorithm finds the loop entry without extra memory.

---

## Guiding the Interviewer from Brute‑Force → Optimal
1. **State the obvious brute‑force** and its `O(n²)` cost.
2. **Ask about constraints** – can we use extra memory? If yes, a hash set gives `O(n)` time.
3. **If memory is restricted**, hint at the *pigeonhole principle*: with `n+1` numbers in `[1,n]` a duplicate must exist.
4. **Lead to the cycle‑detection analogy** – “What if we treat each value as a pointer?" This naturally brings up Floyd’s algorithm.
5. **Explain the two‑phase process** and why it respects `O(1)` space.
6. **Optionally discuss alternative optimal methods** (binary search on value range) to show breadth of knowledge.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters |
|-----------|----------------|
| Duplicate is the smallest number (`1`) | Confirms you aren’t assuming the duplicate is > 1. |
| Duplicate is the largest number (`n`) | Checks off‑by‑one errors. |
| Duplicate appears more than twice | Guarantees your algorithm doesn’t stop after the first repeat in a set‑based solution (it should still return the same value). |
| Very large `n` (e.g., 10⁵) | Tests time‑complexity claims. |
| Array is read‑only (cannot sort in‑place) | Forces the O(1)‑space solution. |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve the problem with binary search on the value range?*  
**A:** Yes. Count how many numbers are ≤ `mid`. If the count > `mid`, the duplicate lies in `[1, mid]`; otherwise it’s in `[mid+1, n]`. This runs in `O(n log n)` time and `O(1)` space.

**Q2:** *Why does Floyd’s algorithm guarantee the meeting point is inside the cycle?*  
**A:** The “slow” pointer moves 1 step, “fast” moves 2 steps. In a linked list with a cycle, the distance between them reduces by 1 each iteration modulo the cycle length, so they eventually coincide.

**Q3:** *What if the array contains **multiple** different duplicates?*  
**A:** The original LeetCode constraint guarantees exactly one duplicated value (though it may appear many times). If multiple duplicates existed, Floyd’s method would still return **a** duplicate but not necessarily all of them; you’d need a different strategy.

**Q4:** *Can we modify the input array?*  
**A:** If mutation is allowed, we could place each number at its index (`while nums[i] != i+1`) and detect a conflict in `O(n)` time and `O(1)` space. However, many interviewers explicitly forbid modification to test the cycle‑detection approach.

---

**Bottom line:** Start with the naïve solution, discuss trade‑offs, and guide the conversation toward the elegant `O(n)` time / `O(1)` space Floyd’s algorithm. This demonstrates problem‑solving depth, knowledge of classic algorithms, and the ability to reason about constraints.
