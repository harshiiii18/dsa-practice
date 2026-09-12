# Palindrome Partitioning II

**Pattern:** Dynamic-Programming
**LeetCode:** https://leetcode.com/problems/palindrome-partitioning-ii/

## Approach / Intuition
The problem asks for the minimum number of cuts needed to partition a string into palindromic substrings. We can solve this using top-down dynamic programming with memoization. The recursive function computes the minimum number of partitions required for the suffix string starting at index `i`. For a given starting index `i`, we iterate through all possible ending indices `j` from `i` to `n-1`. If the substring `s[i...j]` is a valid palindrome, we make a cut and recursively solve for the remaining suffix starting at index `j+1`. The cost for a valid partition ending at `j` is 1 plus the minimum partitions needed for the suffix starting at `j+1`. We memoize the results for each index `i` to avoid recomputing overlapping subproblems. Finally, the minimum cuts needed for the entire string is equal to the total number of partitions minus one.

## Complexity
- **Time:** O(n^3)
- **Space:** O(n)
