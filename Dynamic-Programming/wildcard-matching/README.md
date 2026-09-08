# Wildcard Matching

**Pattern:** Dynamic-Programming
**LeetCode:** https://leetcode.com/problems/wildcard-matching/

## Approach / Intuition
The problem asks whether a pattern string p matches an input string s, where '?' matches any single character and '*' matches any sequence of characters (including an empty sequence). We can solve this using Dynamic Programming where dp[i][j] represents whether the prefix of p of length i matches the prefix of s of length j. The base case dp[0][0] is true since two empty strings match, while dp[i][0] is true only if the first i characters of p consist entirely of '*'. For non-empty prefixes, if the current character p[i-1] equals s[j-1] or is '?', the result depends on dp[i-1][j-1]. If p[i-1] is '*', it can either match zero characters (inheriting from dp[i-1][j]) or match one or more characters (inheriting from dp[i][j-1]). The final state dp[n][m] gives the answer for matching the full pattern against the full string.

## Complexity
- **Time:** O(n * m)
- **Space:** O(n * m)
