# Number of Operations to Make Network Connected

**Pattern:** Union-Find
**LeetCode:** https://leetcode.com/problems/number-of-operations-to-make-network-connected/

## Approach / Intuition
To connect n computers into a single network, we need at least n - 1 edges. If the total number of connections provided is less than n - 1, it is impossible to connect all computers, so we immediately return -1. We can use a Disjoint Set Union (DSU) data structure with path compression and union by rank to count the number of connected components. Initially, each computer is in its own set, giving n connected components. We iterate through each connection (u, v) and check if they belong to different components using the find function. If they are in different components, we merge them using Union and decrement the count of components by 1. Finally, to connect C remaining components into a single connected graph, we need C - 1 operations, so we return components - 1.

## Complexity
- **Time:** O(V + E * α(V))
- **Space:** O(V)
