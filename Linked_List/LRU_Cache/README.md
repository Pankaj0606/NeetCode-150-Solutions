# LRU Cache

## Problem Statement
Design and implement a data structure that follows the **Least Recently Used (LRU)** caching scheme.

- `LRUCache(int capacity)`: Initialize the cache with a positive size `capacity`.
- `int get(int key)`: Return the value of the `key` if the key exists in the cache, otherwise return `-1`.
- `void put(int key, int value)`: Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds `capacity` after the operation, evict the **least recently used** key.

The cache must perform `get` and `put` in **O(1)** time for the optimal solution.

## Core Challenges
1. **Tracking recency** – we need a structure that can move a key to the “most‑recent” position on every access.
2. **Fast lookup** – we must locate a key in O(1) time.
3. **Eviction** – when capacity is exceeded we must remove the *oldest* entry efficiently.

## Approaches
### 1️⃣ Brute‑Force (O(N) per operation)
*Data structures*: `vector`/`ArrayList` storing `(key,value)` pairs in **most‑recent → least‑recent** order.
*Operations*:
- `get`: linear scan to find the key, then move the pair to the front.
- `put`: linear scan to delete an existing key, pop the back if full, then insert at front.
*Complexities*: **Time – O(N)** for both `get` and `put`; **Space – O(N)**.

### 2️⃣ Intermediate Optimization (Amortised O(1) for `put`, O(N) for `get`)
*Data structures*: `HashMap<key,value>` for fast existence/value lookup **plus** a `LinkedList` (or `list` in C++) that stores the order of keys.
*Operations*:
- `get`: check the map (O(1)). If present, linearly locate the node in the list (O(N)), remove it and push to front.
- `put`: if key exists, remove its node from the list (O(N)). If capacity is full, evict the tail (O(1)). Insert the new node at the front (O(1)).
*Complexities*: **Time – `put`: O(1) amortised, `get`: O(N)**; **Space – O(N)**.

### 3️⃣ Optimal (True O(1) for both operations)
*Data structures*: 
- **Doubly linked list** (`list` in C++ / `LinkedList` in Java) that stores `(key,value)` pairs. The front is the most‑recent, the back is the least‑recent.
- **Hash map** that maps `key → iterator/node` of the list.
*Operations*:
- `get`: locate the node via the hash map (O(1)), splice it to the front of the list (O(1)), and return its value.
- `put`: if key exists, update its value and move to front. Otherwise, if at capacity, remove the tail node and erase its entry from the map, then insert the new node at the front and store its iterator in the map.
*Complexities*: **Time – O(1)** for both `get` and `put`; **Space – O(N)**.

## Interview Narrative – From Brute to Optimal
1. **Start with the obvious** – a simple array/list. Explain that it works but each access is linear, which fails the O(1) requirement.
2. **Identify the two requirements** – fast lookup **and** fast ordering. Propose a hash map for lookup and a linked list for ordering.
3. **Spot the missing link** – without a way to jump directly to a node in the list, we still need O(N) to move it. This leads to the insight: *store the iterator/pointer in the hash map*.
4. **Present the final design** – a hash map of iterators + a doubly linked list, achieving true O(1).
5. **Discuss language‑specific helpers** – e.g., Java’s `LinkedHashMap` with `accessOrder=true` gives the optimal behaviour out‑of‑the‑box.

## Edge Cases Interviewers Love
- `capacity == 0` – the cache should never store anything.
- Re‑inserting an existing key with a new value.
- Repeated `get` on a missing key.
- Sequence that fills the cache, then accesses all keys to change their recency before another insertion.
- Large number of operations (≥10⁵) to ensure no hidden O(N²) behaviour.

## Mock Interview Follow‑up Q&As
| Question | Expected Answer |
|---|---|
| *Why can’t we use a single `std::unordered_map` with timestamps?* | Timestamps require a priority structure to find the smallest timestamp on eviction, leading to O(log N) operations. The linked‑list approach gives O(1) eviction. |
| *What would change if we needed a **Most Recently Used (MRU)** cache?* | Eviction policy flips – we would remove from the **front** instead of the back. The rest of the data structures stay the same. |
| *Can we make the cache thread‑safe?* | Wrap public methods with a mutex or use concurrent collections (`ConcurrentHashMap` + custom lock‑protected list). The core algorithm remains unchanged. |
| *How does `LinkedHashMap` achieve O(1) ordering?* | It maintains a doubly linked list internally and stores each entry’s node reference, exactly the same as our optimal design. |
| *What is the memory overhead of storing iterators?* | Each map entry stores a pointer to a list node (typically 8‑16 bytes) plus the key/value. Overall O(N) extra space, acceptable for interview constraints. |

---
*Prepared for a senior‑level interview – feel free to adapt the explanations to your style!*
