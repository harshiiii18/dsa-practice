# Partition Array for Maximum Sum

**Pattern:** Dynamic-Programming
**LeetCode:** https://leetcode.com/problems/partition-array-for-maximum-sum/

## Approach / Intuition
The problem asks us to partition an array into contiguous subarrays of length at most k such that each element in a partition is changed to the maximum value of that partition, maximizing the overall sum. We solve this using top-down Dynamic Programming with memoization. We define a recursive function where f(i) represents the maximum partition sum achievable from index i to the end of the array. Starting at index i, we iterate through all possible partition sizes from 1 up to k (or until the array boundary). As we expand the partition to index j, we maintain the running maximum element maxi of the current subarray arr[i...j]. The contribution of this partition is calculated as len * maxi plus the optimal answer for the remaining subarray starting at j + 1. We take the maximum across all valid partition choices for index i and store it in dp[i] to avoid recomputing overlapping subproblems.

## Complexity
- **Time:** O(n * k)
- **Space:** O(n)
