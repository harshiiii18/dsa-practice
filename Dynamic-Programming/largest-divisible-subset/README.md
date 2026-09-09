# Largest Divisible Subset

**Pattern:** Dynamic-Programming
**LeetCode:** https://leetcode.com/problems/largest-divisible-subset/

## Approach / Intuition
The problem asks for the largest subset of elements such that every pair satisfies divisibility. We can solve this using a dynamic programming approach similar to finding the Longest Increasing Subsequence (LIS). We define an array `dp` where `dp[i]` stores the size of the largest divisible subset ending at index `i`, initialized to 1. To reconstruct the subset later, we maintain a `hash` array initialized to -1 to record the parent index of each element in the chain. For each index `i`, we iterate through all preceding indices `j` and check if `nums[i]` and `nums[j]` are divisible by each other. If divisible and appending `nums[i]` to `dp[j]` yields a larger subset size than `dp[i]`, we update `dp[i] = dp[j] + 1` and record `hash[i] = j`. After completing the DP table, we identify the index with the maximum `dp` value. Finally, we backtrack through the `hash` array starting from this max index to construct the subset, reverse it to preserve the sequence order, and return the result.

## Complexity
- **Time:** O(n^2)
- **Space:** O(n)
