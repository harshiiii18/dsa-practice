# Wildcard Matching

**Pattern:** Dynamic-Programming
**LeetCode:** https://leetcode.com/problems/wildcard-matching/

## Approach / Intuition
The problem can be solved using 2D dynamic programming by comparing prefixes of the pattern string p and the text string s. Let dp[i][j] represent whether the prefix of p of length i matches the prefix of s of length j. The base case dp[0][0] is true because two empty strings match, while dp[0][j] for j > 0 is false. The prefix dp[i][0] is set to true as long as p only contains '*' characters up to index i-1. During state transitions, if the character p[i-1] matches s[j-1] or is '?', then dp[i][j] takes the value of dp[i-1][j-1]. If p[i-1] is '*', it can either match zero characters (taking dp[i-1][j]) or match one or more characters (taking dp[i][j-1]), so dp[i][j] is the logical OR of these two states. The final result is found at dp[n][m].

## Complexity
- **Time:** O(n * m)
- **Space:** O(n * m)
