# Longest Increasing Subsequence

**Pattern:** Dynamic-Programming
**LeetCode:** https://leetcode.com/problems/longest-increasing-subsequence/

## Approach / Intuition
To find the length of the Longest Increasing Subsequence efficiently, we maintain a dynamic list called 'temp' that stores the smallest tail of all increasing subsequences found so far. As we iterate through each element in the array, we compare it with the last element of 'temp'. If the current element is strictly greater than the last element in 'temp', it means we can extend the longest increasing subsequence found so far, so we append it to 'temp'. Otherwise, we use binary search (via std::lower_bound) to find the first element in 'temp' that is greater than or equal to the current number, and replace that element with the current number. Replacing an element with a smaller value does not alter the overall length achieved so far, but it creates a lower threshold for future numbers to extend the subsequence. Finally, the size of 'temp' represents the maximum length of the increasing subsequence.

## Complexity
- **Time:** O(n log n)
- **Space:** O(n)
