# Minimum Cost to Cut a Stick

**Pattern:** Dynamic-Programming
**LeetCode:** https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

## Approach / Intuition
To solve the problem, we use dynamic programming similar to Matrix Chain Multiplication (Interval DP). First, we prepend 0 and append n to the cuts array and then sort it. This allows us to easily compute the length of any segment being cut as cuts[j + 1] - cuts[i - 1]. We define a subproblem dp[i][j] representing the minimum cost to perform all cuts from index i to index j inclusive. To find dp[i][j], we try every possible cut k between i and j as the first cut made on this stick segment, which divides the problem into two independent subproblems: cutting the left portion (i to k - 1) and the right portion (k + 1 to j). We choose the cut k that minimizes the sum of the current cut cost plus the optimal costs of the subproblems. Using bottom-up tabulation or top-down memoization, we build solutions for smaller intervals first to obtain the result for dp[1][c].

## Complexity
- **Time:** O(m^3)
- **Space:** O(m^2)
