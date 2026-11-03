# Subtree of Another Tree

## Problem Statement
Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values as `subRoot` and `false` otherwise.

A **subtree** of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

### Core Challenges
1. **Exact structural match** – not just the same set of values, the shape must be identical.
2. **Handling `null` children** – two trees that differ only by missing children must be distinguished.
3. **Efficiency** – a naïve solution can degrade to *O(N·M)* where *N* and *M* are the number of nodes in `root` and `subRoot` respectively.

---

## Approach 1 – Brute Force (Recursive Comparison)
### Idea
For every node `n` in `root`, treat it as a potential root of the matching subtree and compare the two trees node‑by‑node.

### Algorithm
1. Traverse `root` with a simple DFS.
2. At each node, invoke `isSameTree(n, subRoot)` which recursively checks equality of the two subtrees.
3. If any call returns `true`, the answer is `true`.

### Complexity
- **Time:** `O(N·M)` – in the worst case we compare `subRoot` with every node of `root`.
- **Space:** `O(H₁ + H₂)` recursion stack, where `H₁` and `H₂` are the heights of the two trees.

---

## Approach 2 – Serialize + String Search (Intermediate Optimization)
### Idea
Serialize both trees using a preorder traversal that includes a sentinel for `null` (e.g., `#`). The problem reduces to checking whether the serialized `subRoot` string is a substring of the serialized `root` string.

### Algorithm
1. Perform preorder traversal on both trees, appending `value,` for real nodes and `#,` for nulls.
2. Use the language's built‑in substring search (`find` in C++, `contains` in Java).

### Complexity
- **Time:** `O(N + M)` – linear traversal plus linear substring search (average case).
- **Space:** `O(N + M)` for the two serialized strings.

---

## Approach 3 – Rolling Hash / KMP (Optimal)
### Idea
The previous approach is already linear, but using a robust pattern‑matching algorithm guarantees *O(N+M)* worst‑case time without relying on library heuristics. We can either:
- Apply **KMP** on the two serialized strings, or
- Use a **Rabin‑Karp** rolling hash to compare substrings.
Both avoid the pathological cases of naïve substring search.

### Algorithm (KMP version)
1. Serialize both trees exactly as in Approach 2.
2. Build the KMP prefix table for the pattern (`subRoot` string).
3. Run the KMP matcher on the text (`root` string). If a match is found, return `true`.

### Complexity
- **Time:** `O(N + M)` – linear preprocessing + linear scan.
- **Space:** `O(N + M)` for the strings plus `O(M)` for the prefix table.

---

## From Brute Force to Optimal – How to Explain in an Interview
1. **Start with the obvious:** “I would try every node in `root` and compare the two subtrees.” Mention the `O(N·M)` cost.
2. **Identify the repeated work:** The same subtree structure is compared many times. If we could *represent* a subtree uniquely, we could compare those representations instead of walking the trees each time.
3. **Introduce serialization:** By encoding the shape and values into a string (including null markers), the problem becomes a classic *substring* problem.
4. **Discuss substring search:** The naïve `find` works in practice, but to guarantee linear time we can use KMP or rolling hash – a standard interview‑level optimisation.
5. **Conclude:** This yields an overall `O(N+M)` solution, which is optimal because we must at least read every node once.

---

## Edge Cases Interviewers Love
| Edge case | Why it matters |
|-----------|----------------|
| `subRoot` is `null` | By definition an empty tree is a subtree of any tree – should return `true`.
| `root` is `null` but `subRoot` is not | No possible match – return `false`.
| Trees with duplicate values | Guarantees that simple value‑only checks are insufficient; structural markers (`#`) are essential.
| Very deep (skewed) trees | Tests recursion depth and stack overflow handling – iterative traversals or tail recursion can be discussed.
| Large trees (10⁵ nodes) | Forces you to think about *O(N·M)* vs *O(N+M)* and memory usage of serialized strings.

---

## Mock Interview Follow‑up Q&As
**Q1:** *Can we solve the problem without extra space for the serialized strings?*  
**A:** Yes. We can compute a hash for each subtree in a bottom‑up fashion (e.g., using a pair of modded integers). While traversing `root`, we compare the hash of each subtree with the hash of `subRoot`. This gives `O(N)` time and `O(H)` extra space (recursion stack) – another optimal variant.

**Q2:** *What if the tree nodes contain characters that could be confused with our sentinel (`#`)?*  
**A:** Use a delimiter that cannot appear in the node values (e.g., a comma) and always prepend a sentinel before each value. Alternatively, encode values as strings with length prefixes.

**Q3:** *How would you adapt the solution for a **multiset** of subtrees (find all occurrences)?*  
**A:** After serializing, run a standard pattern‑matching algorithm that records every match index, or store the hash of `subRoot` and collect all nodes in `root` whose subtree hash equals it.

**Q4:** *Can we improve the recursion depth for extremely unbalanced trees?*  
**A:** Yes. Implement the traversals iteratively using an explicit stack, or use Morris traversal for O(1) auxiliary space (though it complicates serialization).

---

## Summary
- **Brute Force:** Simple DFS + direct comparison – `O(N·M)` time.
- **Serialize + Find:** Linear time with built‑in substring search – `O(N+M)`.
- **KMP / Rolling Hash:** Guarantees linear worst‑case time – `O(N+M)` with `O(M)` extra space for the pattern table.

Pick the approach that matches the constraints and the interviewer's expectations. Happy coding!
