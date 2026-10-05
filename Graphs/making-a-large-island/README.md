# Making A Large Island

**Pattern:** Graphs
**LeetCode:** https://leetcode.com/problems/making-a-large-island/

## Approach / Intuition
The problem can be solved using Depth-First Search (DFS) along with component labeling. In the first phase, we iterate over the grid to identify all existing connected components (islands) of 1s. For each island, we assign a unique identifier starting from 2 and run a DFS to compute its total area, storing the mapping of island ID to area in a hash map. In the second phase, we iterate through all cells containing 0. For each 0 cell, we look at its four orthogonal neighbors to identify adjacent unique island IDs. By flipping this 0 to 1, we can connect these distinct neighboring islands into a single larger island. The total size formed by flipping this 0 is 1 plus the sum of the areas of its unique adjacent islands. Finally, we return the maximum area achievable, considering both existing islands and potential merged islands.

## Complexity
- **Time:** O(n^2)
- **Space:** O(n^2)
