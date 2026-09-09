# Largest Divisible Subset

**Pattern:** Dynamic-Programming
**LeetCode:** https://leetcode.com/problems/largest-divisible-subset/

## Approach / Intuition
The problem asks for the largest subset where every pair of elements satisfies the divisibility condition. The solution uses a Dynamic Programming approach similar to finding the Longest Increasing Subsequence (LIS). A DP array `dp` of size `n` is initialized with 1s, where `dp[i]` stores the length of the largest divisible subset ending at index `i`. A tracking array `hash` initialized to -1 stores the index of the previous element in the subset to allow reconstruction of the final answer. Nested loops iterate through all pairs `(i, j)` where `j < i`; if `nums[i]` and `nums[j]` are divisible and extending the sequence from `j` gives a larger length, `dp[i]` and `hash[i]` are updated. After filling the DP table, the index with the maximum value in `dp` is identified. Finally, the code backtracks using the `hash` array starting from this maximum index to reconstruct the largest divisible subset.

## Complexity
- **Time:** O(n^2)
- **Space:** O(n)
