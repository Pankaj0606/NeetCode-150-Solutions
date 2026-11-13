# Implement Trie (Prefix Tree)

## Problem Statement
Design a data structure that supports the following operations efficiently:
- **insert(word)** – Insert a string `word` into the data structure.
- **search(word)** – Return `true` if the exact string `word` was previously inserted.
- **startsWith(prefix)** – Return `true` if there is any previously inserted string that starts with the given `prefix`.

The classic solution is a **Trie (Prefix Tree)** – a tree where each node represents a character and paths from the root spell out stored words.

## Core Challenges
1. **Space vs. Time Trade‑off** – Storing children as a fixed array (size 26 for lowercase English letters) gives O(1) child lookup but wastes memory for sparse nodes. Using a hash map saves space but incurs O(1) average‑case lookup with higher constant factors.
2. **Edge Cases** – Empty strings, duplicate inserts, and queries on non‑existent prefixes must be handled gracefully.
3. **Scalability** – Interviewers often ask you to discuss how the implementation would change for Unicode alphabets or case‑insensitive searches.

## Approaches
### 1️⃣ Brute‑Force (Linear Scan)
- **Idea**: Keep a simple `vector<string>` (C++) or `List<String>` (Java) of all inserted words. `search` and `startsWith` iterate over the collection.
- **Complexities**
  - Insert: **O(1)**
  - Search / startsWith: **O(N·L)** where *N* is the number of words and *L* is the average word length.
- **When to use**: Only when the dataset is tiny or when you need to prototype quickly.

### 2️⃣ Better (Hash‑Map Children)
- **Idea**: Each node stores a `unordered_map<char, Node*>` (C++) or `HashMap<Character, Node>` (Java). This gives fast average‑case child lookup while keeping memory proportional to the actual branching factor.
- **Complexities**
  - Insert: **O(L)**
  - Search / startsWith: **O(L)** (average case)
  - Space: **O(T)** where *T* is the total number of characters across all inserted words.
- **Pros/Cons**
  - Faster than brute‑force, but hash‑map overhead (rehashing, extra pointers) makes it slower than a fixed array for dense alphabets.

### 3️⃣ Optimal (Fixed‑Size Array Children)
- **Idea**: Nodes contain a `Node* child[26]` (C++) or `Node[] child = new Node[26]` (Java). Index is computed as `c - 'a'`.
- **Complexities**
  - Insert: **O(L)**
  - Search / startsWith: **O(L)** (worst‑case constant time per character)
  - Space: **O(26·T)** ≈ **O(T)** but with a larger constant factor due to the 26‑slot array per node.
- **Why it’s optimal**: Guarantees deterministic O(1) child access, minimal pointer indirection, and excellent cache locality.

## Transition Narrative (Brute → Better → Optimal)
1. **Start with the naive list** – Explain that you can get the job done but every query scans the whole list, which is unacceptable for large inputs.
2. **Introduce a tree structure** – Show the mental model of a prefix tree and why it reduces query time to the length of the word.
3. **Discuss child‑storage choices** – First, a hash‑map is a natural go‑to because it’s easy to code and saves space for sparse nodes.
4. **Identify the bottleneck** – In a typical interview, the alphabet is limited (e.g., lowercase English). Point out that a fixed array eliminates hash‑map overhead and gives O(1) child lookup.
5. **Conclude with the optimal solution** – Present the array‑based implementation, mention trade‑offs for larger alphabets, and optionally discuss how to extend it (e.g., using a vector of size `ALPHABET_SIZE` or a map for Unicode).

## Edge Cases Interviewers Love
- Inserting an empty string (`""`).
- Searching for a word that is a prefix of an existing word and vice‑versa.
- Re‑inserting the same word multiple times.
- Queries on a prefix that matches no word.
- Using characters outside the assumed range (e.g., uppercase or digits) – discuss defensive checks.

## Mock Interview Follow‑up Q&As
| # | Question | Expected Answer |
|---|----------|-----------------|
| 1 | *What is the time complexity of `search` if we used a balanced BST at each node instead of a hash‑map?* | `O(L·log σ)` where `σ` is the number of distinct children (alphabet size). |
| 2 | *How would you modify the Trie to support deletion of a word?* | Walk down the word, unset the `isEnd` flag, and optionally prune nodes that have no children and are not end‑of‑word. |
| 3 | *If the input alphabet were Unicode (≈100k code points), which implementation would you choose and why?* | Use a hash‑map (or `std::unordered_map` / `HashMap`) to keep space proportional to actual branching; a fixed array would be prohibitive. |
| 4 | *Can you compute the number of words stored in the Trie without storing an extra counter?* | Perform a DFS counting nodes where `isEnd` is true; O(T) time, O(H) recursion stack where H is the height. |

---
**Key Takeaway:** Start simple, justify each optimization, and always be ready to discuss trade‑offs and extensions. Happy coding!
