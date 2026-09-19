# Encode and Decode Strings

## Problem Statement
Design an algorithm to encode a list of strings into a single string and decode that string back to the original list. The solution must handle any possible characters in the original strings.

## Core Challenges
- Choosing a representation that is **unambiguous** for any input.
- Keeping the encoding/decoding **O(N)** where N is the total number of characters.
- Avoiding collisions with delimiters that may appear in the strings.

## Approaches

### 1. Brute‑Force (Escape Delimiter)
Encode each string by escaping a chosen delimiter (e.g., `|`) and join them with the delimiter.  
**Time:** O(N)  
**Space:** O(N)

### 2. Better (Length‑Prefix)
Prefix each string with its length followed by a special separator (`#`).  
**Time:** O(N)  
**Space:** O(N)

### 3. Optimal (Manual Length Parsing)
Same idea as the length‑prefix approach but parses the length without converting to a temporary string, saving a small constant factor.  
**Time:** O(N)  
**Space:** O(N)

## Transition Talk in an Interview
1. Start with the naïve delimiter idea → point out ambiguity when the delimiter appears in the data.
2. Propose escaping → discuss overhead and edge‑case handling.
3. Move to length‑prefix → show it removes ambiguity and is still linear.
4. Refine by parsing the length manually → demonstrate attention to detail and constant‑factor optimisation.

## Edge Cases Interviewers Love
- Empty string `""` in the list.
- Strings containing the delimiter or `#`.
- Very long strings (testing integer overflow in length handling).
- List with a single element or an empty list.

## Mock Interview Follow‑up Q&A

**Q1:** *What if the total length exceeds `int` range?*  
**A:** Use a 64‑bit type (`long long` in C++, `long` in Java) for the length field.

**Q2:** *Can we avoid the separator character?*  
**A:** Yes, by using a fixed‑width length field (e.g., 4‑byte binary) or by encoding lengths in base‑256, but that complicates the implementation.

**Q3:** *How would you handle Unicode characters?*  
**A:** The algorithms work on the raw byte/character sequence; just ensure the length counts code units (UTF‑8 bytes) consistently.

**Q4:** *Is it possible to achieve O(1) extra space?*  
**A:** The encoding itself must produce a new string, so O(N) output space is unavoidable. The algorithmic extra space can be kept O(1) besides the output container.
