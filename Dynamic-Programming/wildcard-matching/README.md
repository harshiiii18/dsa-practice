# Wildcard Matching

**Pattern:** Dynamic-Programming
**LeetCode:** https://leetcode.com/problems/wildcard-matching/

## Approach / Intuition
The problem asks whether a pattern string containing wildcard characters ('?' and '*') matches an input string. This can be solved using 2D Dynamic Programming, where `dp[i][j]` represents whether the prefix of length `i` of pattern `p` matches the prefix of length `j` of string `s`. The base case `dp[0][0]` is true because two empty strings match. For non-empty patterns against an empty string, `dp[i][0]` is true only if all characters up to index `i` in `p` are '*'. When transitioning, if the current characters match (`p[i-1] == s[j-1]`) or `p[i-1]` is '?', the result depends on `dp[i-1][j-1]`. If `p[i-1]` is '*', it can either represent an empty character sequence (taking `dp[i-1][j]`) or extend a sequence by matching `s[j-1]` (taking `dp[i][j-1]`). The final answer is stored in `dp[n][m]`.

## Complexity
- **Time:** O(n * m)
- **Space:** O(n * m)
