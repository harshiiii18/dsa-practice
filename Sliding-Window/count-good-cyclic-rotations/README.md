# Count Good Cyclic Rotations

**Pattern:** Sliding-Window
**LeetCode:** https://leetcode.com/problems/count-good-cyclic-rotations/

## Approach / Intuition
The problem requires counting the number of cyclic rotations of an array where the sum of the first half of the rotated array is strictly greater than the sum of the second half. To simulate all cyclic rotations efficiently without repeatedly recomputing sums, we duplicate the elements of the array into a temporary array. We calculate the initial sums $f$ and $s$ representing the first half (length $n/2$) and second half of the unshifted array, respectively. As we slide the starting index across all $n$ possible cyclic shifts, we update $f$ and $s$ in $O(1)$ time by subtracting the element that falls out of the range and adding the new element that enters the window. After each shift update, we check if $f > s$ and increment our answer counter accordingly. Finally, we return the total number of good rotations.

## Complexity
- **Time:** O(n)
- **Space:** O(n)
