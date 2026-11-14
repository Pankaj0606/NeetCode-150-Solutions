# Design Add and Search Word Data Structure

## Problem Statement
Implement a data structure that supports two operations:
- `addWord(word)`: Insert a word consisting of lowercase English letters.
- `search(word)`: Return `true` if there is any previously added string that matches the given **search word**. The search word may contain the wildcard character `'.'` which can represent any single letter.

This is the classic LeetCode problem *211. Design Add and Search Words Data Structure*.

## Core Challenges
1. **Wildcard handling** – `'.'` can match any character, so a naïve hash‑map lookup is insufficient.
2. **Performance trade‑offs** – A naïve linear scan is simple but slow for large dictionaries. We need a structure that can prune the search space efficiently.
3. **Memory vs. speed** – Trie nodes give fast look‑ups but consume extra memory; grouping by length is a middle ground.

---

## Approaches
### 1️⃣ Brute‑Force (Worst‑Case)
- **Idea**: Store every added word in a simple container (e.g., `vector`/`ArrayList`). For `search`, iterate over all stored words and compare character‑by‑character, treating `'.'` as a wildcard.
- **Complexities**:
  - `addWord`: **O(1)**
  - `search`: **O(N·L)** where *N* is the number of stored words and *L* is the average word length.
  - **Space**: **O(N·L)** (just the stored words).
- **When to use**: Small input size, quick prototype, or when interviewers explicitly ask for a naïve solution.

### 2️⃣ Length‑Bucket (Better / Intermediate)
- **Idea**: Group words by their length using a hash map (`Map<Integer, List<String>>`). When searching, only compare against words of the same length, dramatically reducing candidates.
- **Complexities**:
  - `addWord`: **O(1)** amortised (insert into the correct bucket).
  - `search`: **O(K·L)** where *K* is the number of words sharing the same length as the query.
  - **Space**: Same as brute‑force, plus the overhead of the map.
- **Why it helps**: The wildcard does not change word length, so mismatched‑length words can be discarded instantly.

### 3️⃣ Trie with DFS (Optimal)
- **Idea**: Build a classic 26‑ary Trie. Each node stores a `bool isEnd` and an array of child pointers. For `search`, perform a depth‑first traversal:
  - If the current character is a letter, follow the corresponding child.
  - If it is `'.'`, recursively explore **all** existing children.
- **Complexities**:
  - `addWord`: **O(L)**
  - `search`: **O(26^M)** in the worst case where *M* is the number of wildcards, but on average **O(L)** because the trie prunes branches.
  - **Space**: **O(T)** where *T* is the total number of characters inserted (each creates a node).
- **Why it’s optimal**: The trie eliminates irrelevant branches early, giving near‑linear time for typical queries while keeping memory proportional to the total input size.

---

## Transition Narrative (Interview Flow)
1. **Start with the brute‑force** – Explain the simplest way to satisfy the API. Show the `O(N·L)` search and discuss its drawbacks.
2. **Identify the bottleneck** – The linear scan over *all* words. Mention that the wildcard does **not** affect word length.
3. **Introduce length‑bucket** – Show how grouping by length cuts the candidate set dramatically, turning the worst‑case factor from *N* to *K*.
4. **Push further with a Trie** – Explain that a Trie naturally encodes prefix information, allowing us to skip whole sub‑trees when a character mismatch occurs. Demonstrate the DFS handling of `'.'`.
5. **Conclude** – Summarize the trade‑offs and why the Trie is the preferred production‑grade solution.

---

## Edge Cases Interviewers Love
| Edge Case | Why it matters | How we handle it |
|-----------|----------------|-----------------|
| Empty string (`""`) | Some implementations forget to mark the root as a word. | Store `isEnd` at the root; both `addWord("")` and `search("")` work.
| All wildcards (`"..."`) | Forces the algorithm to explore many branches. | Trie DFS naturally explores all children at each level; still correct.
| Very long word (e.g., length 1000) | Tests recursion depth and memory. | Use iterative stack for DFS if needed; typical recursion depth is safe in LeetCode limits.
| Duplicate adds | Should not break the structure. | Insertion simply sets `isEnd = true`; duplicates are idempotent.
| Search for a word never added | Must return `false`. | Trie returns `false` when traversal ends early or `isEnd` is not set.

---

## Mock Interview Follow‑up Q&A
**Q1:** *Can we improve the worst‑case `search` when the query is all `'.'`?*  
**A:** Yes, we could store the total number of words of each length and return `true` immediately if that count > 0. However, this only answers existence, not exact matching of patterns with mixed letters.

**Q2:** *What if we need to support deletions?*  
**A:** In the Trie we can decrement a `prefixCount` at each node and clear `isEnd` when the word count drops to zero, optionally pruning empty nodes to save memory.

**Q3:** *How would you adapt the solution for Unicode characters?*  
**A:** Replace the fixed 26‑size child array with a `Map<Character, Node>` (e.g., `unordered_map<char, Node*>` in C++ or `HashMap<Character, Node>` in Java). The rest of the algorithm stays the same.

**Q4:** *Is there a way to make the Trie iterative to avoid recursion limits?*  
**A:** Yes, use an explicit stack that stores `(node, index)` pairs while processing the query string.

---

## Summary
- **Brute‑Force**: Simple, O(N·L) search.
- **Length‑Bucket**: Improves to O(K·L) by discarding mismatched lengths.
- **Trie + DFS**: Near O(L) average search, optimal for large dictionaries.

Choose the implementation that matches the constraints you’re given, and be ready to discuss the trade‑offs during the interview.
