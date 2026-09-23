# Valid Parentheses

## Problem Statement
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

A string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

## Core Challenges
- Matching corresponding opening and closing brackets.
- Handling nesting and order.
- Detecting early invalid cases.

## Approaches

### 1. Brute Force (O(n²) time, O(1) extra space)
Repeatedly scan the string and remove any adjacent matching pair `()`, `{}`, `[]` until no more removals are possible. If the string becomes empty, it is valid.

**Pros:** Simple to explain.  
**Cons:** Each removal may require shifting characters → quadratic time.

### 2. Better / Intermediate (O(n) time, O(n) space)
Use a stack to push opening brackets. For each closing bracket, check the top of the stack; if it matches, pop it, otherwise the string is invalid.

**Pros:** Linear time, easy to implement.  
**Cons:** Uses extra space proportional to the depth of nesting.

### 3. Optimal (O(n) time, O(n) space, constant‑time operations)
Same stack idea but implemented with a fixed‑size array (or `char[]`) to avoid the overhead of `std::stack` / `java.util.Stack`. Early exit on mismatch and final size check give the optimal constant factors.

**Pros:** Linear time, minimal overhead.  
**Cons:** Still O(n) auxiliary space in the worst case (cannot be avoided because we need to remember unmatched openings).

## Transition from Brute Force to Optimal in an Interview
1. **Identify the bottleneck:** Brute‑force repeatedly scans the string → O(n²).  
2. **Ask for a single pass:** “Can we decide validity while scanning once?”  
3. **Introduce a data structure:** A stack naturally models the LIFO nature of brackets.  
4. **Optimize the stack:** Replace `std::stack`/`java.util.Stack` with an array for speed and avoid boxing.  
5. **Discuss edge‑case handling:** Early returns, empty stack checks, and final stack emptiness.

## Edge Cases Interviewers Love
- Empty string `""` → valid.
- Single opening or closing bracket `"("`, `"]"` → invalid.
- Interleaved but non‑nested brackets `"([)]"` → invalid.
- Long string of only opening brackets `"(((..."` → invalid.
- Long string of only closing brackets `"...)))"` → invalid.

## Mock Interview Follow‑up Q&A

**Q1:** *Can we solve this without extra space?*  
**A:** Not in the general case because we need to remember unmatched opening brackets. The best we can do is O(1) extra space if we modify the input string in‑place, but that destroys the input.

**Q2:** *What if the input contains other characters?*  
**A:** We can ignore non‑bracket characters or treat them as invalid depending on the specification. The algorithm can be extended with a simple `if` check.

**Q3:** *How would you adapt the solution for Unicode bracket pairs?*  
**A:** Use a hash map that maps closing Unicode characters to their opening counterpart and keep the same stack logic.

**Q4:** *What is the time complexity if the string is already valid?*  
**A:** Still O(n) because we must examine each character once; early exit only helps for invalid prefixes.
