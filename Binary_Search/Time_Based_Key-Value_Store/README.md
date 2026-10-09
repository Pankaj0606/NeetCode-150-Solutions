# Time‑Based Key‑Value Store

## Problem Statement
Implement a data structure that can store multiple values for the same key at different timestamps and retrieve the value for a given key at a particular timestamp.

- **set(key, value, timestamp)** – Store the key‑value pair along with the given timestamp. Timestamps for a particular key are **strictly increasing**.
- **get(key, timestamp)** – Return the value associated with `key` such that its timestamp is the **largest** timestamp less than or equal to `timestamp`. If no such timestamp exists, return an empty string.

The classic LeetCode signature is:
```cpp
class TimeMap {
public:
    void set(string key, string value, int timestamp);
    string get(string key, int timestamp);
};
```
```java
class TimeMap {
    public void set(String key, String value, int timestamp) {}
    public String get(String key, int timestamp) { return ""; }
}
```

## Core Challenges
1. **Efficient retrieval** – We need the *closest* timestamp ≤ query timestamp.
2. **Monotonic timestamps** – For each key timestamps are inserted in increasing order, which we can exploit.
3. **Space vs. time trade‑offs** – Storing data in a way that makes `get` fast without blowing up memory.

---

## Approaches
### 1️⃣ Brute‑Force (Linear Scan)
*Data structure*: `unordered_map<string, vector<pair<int,string>>>` (C++) / `Map<String, List<Pair>>` (Java).
*`set`*: Append to the vector/list – **O(1)**.
*`get`*: Scan the vector from the end until we find a timestamp ≤ query – **O(N)** where *N* is the number of entries for that key.

**When to use**: First implementation in an interview to show you understand the problem. It works but is too slow for large inputs.

---

### 2️⃣ Intermediate Optimization (Ordered Map / Reverse Linear Scan)
*Data structure*: `unordered_map<string, map<int,string>>` (C++) or `Map<String, TreeMap<Integer,String>>` (Java).
*`set`*: Insert into the ordered map – **O(log N)**.
*`get`*: Use `upper_bound`/`floorKey` to locate the greatest timestamp ≤ query – **O(log N)**.

**Why it’s better**: Guarantees logarithmic lookup without having to manage a separate vector. Slightly higher constant factor than the final optimal solution.

---

### 3️⃣ Optimal Approach (Binary Search on a Vector)
*Data structure*: Same as brute‑force (vector per key) but leverage the fact that timestamps are **strictly increasing**.
*`set`*: Append – **O(1)**.
*`get`*: Perform binary search on the timestamp vector – **O(log N)**.

**Why it’s optimal**:
- Append is constant time.
- Binary search gives the fastest possible lookup for a sorted array.
- Memory overhead is minimal (just the stored pairs).

---

## Complexity Summary
| Approach | `set` Time | `get` Time | Space |
|----------|------------|------------|-------|
| Brute‑Force | O(1) | O(N) | O(total entries) |
| Ordered Map | O(log N) | O(log N) | O(total entries) |
| Binary‑Search Vector (Optimal) | O(1) | O(log N) | O(total entries) |

---

## Explaining the Transition in an Interview
1. **Start with the naive solution** – Show the linear scan, discuss its correctness, and point out the `O(N)` lookup cost.
2. **Ask a probing question** – “Can we do better than scanning every entry?”
3. **Leverage the monotonic property** – Mention that timestamps are inserted in order, so the data is naturally sorted.
4. **Introduce binary search** – Explain how binary search on a sorted array gives `O(log N)`.
5. **Compare with an ordered map** – Acknowledge that a `TreeMap`/`std::map` also gives `log N` but with higher constant factors and extra node overhead.
6. **Conclude with the optimal vector‑based solution** – Emphasize constant‑time inserts and minimal memory.

---

## Edge Cases Interviewers Love
| Edge Case | Why it matters | How we handle it |
|-----------|----------------|-----------------|
| Query timestamp **earlier** than any stored timestamp | Should return empty string | Binary search returns `-1` → return "" |
| Multiple `set` calls with the **same timestamp** (though problem guarantees increasing) | Test robustness | Our implementations either overwrite (map) or keep the later entry (vector) – both return the latest value |
| Key **does not exist** | Must not crash | Check map existence and return "" |
| Very large number of timestamps for a single key | Stress test for time complexity | Optimal solution stays `O(log N)` per `get` |
| Interleaved keys with different lengths | Ensure isolation per key | Separate containers per key |

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we achieve `O(1)` for `get`?*  
**A:** Only if we pre‑compute answers for every possible timestamp, which is infeasible because timestamps can be up to `10^9`. The lower bound for ordered retrieval is `O(log N)`.

**Q2:** *What if timestamps are **not** strictly increasing?*  
**A:** We would need to keep the vector sorted after each insertion (e.g., `std::lower_bound` + `insert`) which makes `set` `O(log N)`. The rest of the algorithm stays the same.

**Q3:** *How would you modify the design for a **distributed** system?*  
**A:** Partition by key, store each partition in a time‑ordered log (e.g., Kafka), and use a local binary‑search store per partition. Consistency can be achieved with version vectors.

**Q4:** *Can we reduce space by discarding old timestamps?*  
**A:** If a retention policy exists, we can prune entries older than a threshold, but we must ensure `get` semantics still hold for allowed timestamps.

---

## TL;DR
- **Brute‑force**: simple vector + linear scan (`O(N)` get).
- **Ordered map**: `TreeMap`/`std::map` gives `O(log N)` get and set.
- **Optimal**: keep a vector per key and binary‑search (`O(1)` set, `O(log N)` get) – the best trade‑off for this problem.

Happy coding!
