# Car Fleet – Interview Guide

## Problem Statement
You are given a target distance `target` and two integer arrays `position` and `speed` of the same length `n`. The `i`‑th car starts at `position[i]` and moves toward the target at a constant speed `speed[i]`. When a faster car catches up to a slower car, it **joins** the slower car's fleet and they move together at the slower car's speed. A **car fleet** is a group of cars that travel together and reach the target at the same time.

Return the number of distinct car fleets that will arrive at the target.

### Core Challenges
1. **Relative motion** – a car can only affect cars *ahead* of it.
2. **Merging rule** – once two cars meet, they become a single entity with the slower arrival time.
3. **Ordering** – the answer depends on the ordering of cars by their starting positions.
4. **Precision** – we work with floating point arrival times.

---

## Approaches
### 1️⃣ Brute‑Force (O(n²) time, O(n) space)
* Compute the arrival time for every car: `t[i] = (target‑position[i]) / speed[i]`.
* For each car `i`, look at every car `j` that starts **ahead** (`position[j] > position[i]`).
* If `t[j] <= t[i]`, car `i` will catch up to `j` before the target, so they belong to the same fleet. Mark `j` as already merged.
* Count a new fleet whenever we encounter an un‑merged car.

**Why it works** – we explicitly simulate the pairwise catch‑up relationship.

**Drawbacks** – quadratic scans are too slow for `n` up to 10⁵.

---
### 2️⃣ Better / Intermediate (O(n log n) time, O(n) space)
1. **Sort** cars by starting position **descending** (furthest from the target first).
2. Compute the arrival time for each car in that order.
3. Use a **stack** (or a vector as a stack) to keep the arrival times of fleets seen so far.
   * If the current car's time `t` is **greater** than the time on the top of the stack, it cannot catch the fleet ahead → push `t` (new fleet).
   * Otherwise, it merges with the fleet on the top (do nothing).
4. The stack size at the end equals the number of fleets.

**Why it works** – after sorting, a car can only interact with cars that appear earlier in the list. The stack stores the *slowest* arrival time of each fleet seen so far.

---
### 3️⃣ Optimal (O(n log n) time, O(1) extra space) – “Stack‑less” Scan
The same sorting step is required (O(n log n)). After sorting we can avoid an explicit stack by keeping a single variable `lastFleetTime`:
* Iterate the sorted cars.
* If the current car's arrival time `t` is **greater** than `lastFleetTime`, it starts a new fleet → increment answer and set `lastFleetTime = t`.
* Otherwise it merges with the fleet represented by `lastFleetTime`.

The algorithm uses only a few scalar variables, achieving O(1) auxiliary space while retaining the optimal O(n log n) time.

---
## From Brute‑Force to Optimal – How to Explain in an Interview
1. **Start with the definition** – “a car can only affect cars in front of it”.
2. **Brute‑Force** – show the naïve O(n²) double loop and discuss why it times out.
3. **Observation** – after sorting by position, the interaction becomes *one‑directional*.
4. **Introduce a stack** – each new car either creates a new fleet or merges with the fleet on top.
5. **Space optimisation** – notice we only need the *last* fleet time, not the whole stack, leading to the O(1) version.
6. **Complexity recap** – O(n log n) dominated by sorting, O(1) extra space.

---
## Edge Cases Interviewers Love
| Edge case | Reason it trips candidates |
|-----------|----------------------------|
| `position` empty | Must return 0 without errors. |
| All cars have the **same speed** | No merging; answer = number of cars. |
| Cars already **sorted** vs **unsorted** input | Forgetting to sort leads to wrong answer. |
| A car **exactly** catches another at the target (`t[i] == t[j]`) | Should be counted as the **same** fleet. |
| Large values (`target` up to 10⁹) | Watch out for integer overflow; use `double` for times. |

---
## Mock Interview Follow‑up Q&A
**Q1:** *Can we solve the problem in O(n) without sorting?*  
**A:** Only if the input is already sorted by position. Otherwise sorting is required because the relative order determines merging.

**Q2:** *What if the cars could move backwards?*  
**A:** The current merging rule would break; we would need a more complex simulation (e.g., sweep line) and the O(n log n) guarantee no longer holds.

**Q3:** *How would you adapt the solution for floating‑point positions/speeds?*  
**A:** The same algorithm works; just store times as `double`. Be careful with precision when comparing equality – use a small epsilon.

**Q4:** *Can we use a priority queue instead of a stack?*  
**A:** Yes, but it adds unnecessary O(log n) per operation. The stack (or single variable) is sufficient because we only need the most recent fleet time.

---

**Happy coding!**
