# Word Search II – Interview Guide

## Problem Statement
Given an `m x n` board of characters and a list of strings `words`, return all words that can be formed by sequentially adjacent cells on the board. Adjacent cells are horizontally or vertically neighboring. The same cell may **not** be used more than once in a single word.

### Core Challenges
1. **Huge search space** – naive DFS for each word leads to exponential blow‑up.
2. **Multiple words share prefixes** – we can reuse work across words.
3. **In‑place visitation** – we must mark cells visited without extra memory per recursion.
4. **Pruning** – stop exploring dead‑ends early to keep runtime acceptable.

---

## Approaches
### 1️⃣ Brute‑Force (Word‑by‑Word DFS)
For every word we run a classic *Word Search* DFS on the board.
```text
for each word:
    for each cell (i,j):
        if dfs(i,j,0) -> found
```
**Complexities**
- **Time:** `O(W * m * n * 4^L)` where `W` = number of words, `L` = average word length.
- **Space:** `O(L)` recursion stack + `O(m*n)` visited matrix.

### 2️⃣ Better (Trie + Single Board Traversal, No Node Deletion)
Build a **Trie** from all words. Then start a DFS from every cell, walking the Trie simultaneously. Whenever we hit a node that marks the end of a word we add it to the answer set.
- We **do not** delete nodes after a word is found, so the Trie stays intact.

**Complexities**
- **Time:** `O(m * n * 4 * L)` – each board cell is visited at most `4*L` times (the length of the longest word).
- **Space:** `O(T + L)` where `T` is total characters in the Trie.

### 3️⃣ Optimal (Trie + Pruning via Node Deletion)
Same as the better approach, but after we record a word we **remove the leaf node** (or the whole branch) from the Trie. This prevents re‑exploring paths that can no longer yield new words, dramatically cutting the constant factor.

**Complexities**
- **Time:** Still `O(m * n * 4 * L)` in the worst case, but practically much faster because dead branches disappear.
- **Space:** Same as the better approach, plus a tiny overhead for the deletion logic.

---

## Explaining the Transition in an Interview
1. **Start with the obvious** – “For each word, run the classic DFS.” Show you understand the baseline.
2. **Identify the pain point** – repeated work for common prefixes, exponential blow‑up.
3. **Introduce a Trie** – “We can share prefixes across words, so we traverse the board only once.”
4. **Add pruning** – “If a word is found, we can delete that branch; future traversals won’t waste time on it.”
5. **Summarize** – “Thus we go from `W * m * n * 4^L` to essentially `m * n * 4 * L` with a small extra memory cost.”

---

## Edge‑Case Checklist (Interviewers love these!)
| Edge case | Why it matters | How we handle |
|-----------|----------------|--------------|
| Empty board or empty `words` list | Should return empty vector | Early return checks |
| Words longer than `m*n` | Impossible to fit | Skip during Trie insertion or early prune |
| Duplicate words in input | Should appear only once in output | Use `unordered_set` for results |
| Board containing only one character repeated | Many overlapping paths – tests pruning effectiveness | Trie deletion removes already‑found words |
| Very large board (e.g., 12x12) with thousands of words | Stress test for time & memory | Trie reduces repeated scans |

---

## Mock Interview Follow‑up Q&A
**Q1:** *Why can’t we just sort the words and stop the DFS when the current prefix is lexicographically larger?*  
**A:** Sorting doesn’t help because the board traversal order is unrelated to lexical order. Prefix pruning must be based on **actual** possible continuations, which a Trie provides.

**Q2:** *What if we need to return words in alphabetical order?*  
**A:** Collect results in a `set` (C++) or `TreeSet` (Java) after the search, or sort the final vector before returning. The core algorithm remains unchanged.

**Q3:** *Can we use DP instead of a Trie?*  
**A:** DP works for a **single** word (Word Search I) but becomes infeasible for thousands of words because the state space explodes. A Trie is the natural structure to share sub‑problems.

**Q4:** *How would you adapt the solution for diagonal moves?*  
**A:** Extend the direction vectors from 4 to 8. The rest of the algorithm (Trie walk, pruning) stays identical.

---

## TL;DR
- **Brute‑Force:** DFS per word → exponential.
- **Better:** Build a Trie, DFS board once, collect words.
- **Optimal:** Same as Better **plus** delete visited Trie nodes to prune dead branches.
- Use in‑place marking (`board[i][j] = '#'`) for O(1) extra space per recursion.
- Return results as a vector of unique strings.

Happy coding! 🎉
