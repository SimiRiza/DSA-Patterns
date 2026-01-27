# 0922 — Sort Array By Parity II

## Problem
Rearrange the array so that:
- Even indices contain even numbers
- Odd indices contain odd numbers

It is guaranteed that the input has equal even and odd elements.

---

## Solutions

### 1️⃣ Two-Pointer (Interview-Friendly)
**File:** `0922_Parity_II_TwoPointer.cpp`

- Uses two pointers for even and odd indices
- Clear, symmetric logic
- Easy to explain in interviews

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 2️⃣ Alternate Odd-First Approach
**File:** `0922_Parity_II_Alternate.cpp`

- Focuses on fixing odd indices first
- Also runs in O(n) time and O(1) space
- Shows an alternative way to reason about the problem

---

## Notes
- Primary recommended solution: Two-pointer approach
- Alternate solution kept to demonstrate different reasoning
