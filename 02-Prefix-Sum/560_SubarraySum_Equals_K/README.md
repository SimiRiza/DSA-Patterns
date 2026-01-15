# 0560. Subarray Sum Equals K

## Problem
Given an integer array `nums` and an integer `k`, return the total number of
subarrays whose sum equals `k`.

---

## Approaches Used

| Approach | Idea | Time | Space |
|--------|------|------|-------|
| Brute Force | Check every subarray using 3 loops | O(n³) | O(1) |
| Prefix Sum Array | Precompute prefix sums | O(n²) | O(n) |
| Running Sum | Extend subarray while tracking sum | O(n²) | O(1) |
| HashMap (Optimal) | Store frequency of prefix sums | O(n) | O(n) |

---

## Files
- `0560_Subarray_Sum_Equals_K_BruteForce.cpp`
- `0560_Subarray_Sum_Equals_K_PrefixSum_Array.cpp`
- `0560_Subarray_Sum_Equals_K_Running_Sum.cpp`
- `0560_Subarray_Sum_Equals_K_HashMap.cpp`

---

## Key Learning
Same problem, different thinking levels:
Brute force → Prefix sum → Optimization → HashMap trick.
