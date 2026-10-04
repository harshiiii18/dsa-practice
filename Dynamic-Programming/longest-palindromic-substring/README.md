# Longest Palindromic Substring

**Pattern:** Dynamic-Programming
**LeetCode:** https://leetcode.com/problems/longest-palindromic-substring/

## Approach / Intuition
We evaluate all possible substrings of the input string `s` to find the longest one that forms a palindrome. To optimize the palindrome checks, we use top-down dynamic programming with memoization. A recursive function `solve(l, r)` checks if the substring `s[l..r]` is a palindrome by verifying if the outer characters `s[l]` and `s[r]` match and then checking the inner substring `s[l+1..r-1]`. A 2D array `t[1001][1001]` stores the boolean result for each subproblem `(l, r)` so each state is computed at most once. We iterate through every pair of indices `(i, j)`, check if `s[i..j]` is a palindrome, and maintain the starting index and length of the longest palindrome encountered. Finally, we return the longest palindromic substring using `s.substr()`.

## Complexity
- **Time:** O(n^2)
- **Space:** O(n^2)
