class Solution {
public:
    vector<vector<int>> direction{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int n;
    int dfs(int i, int j, vector<vector<int>>& grid, int id) {
        if (i < 0 || j < 0 || i >= n || j >=n||
            grid[i][j] != 1)
            return 0;

        grid[i][j] = id;
        int size = 1;

        for (auto& dir : direction) {
            int x = i + dir[0];
            int y = j + dir[1];

            size += dfs(x, y, grid, id);
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> mp;

        int uniqueId = 2;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, grid, uniqueId);
                    mp[uniqueId] = size;
                    maxArea = max(maxArea, size);
                    uniqueId++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> ids;
                    for (auto& dir : direction) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && y >= 0 && x < n && y < n &&
                            grid[x][y] != 0) {
                            ids.insert(grid[x][y]);
                        }
                    }
                    int overAllSize = 1;
                    for (auto& it : ids) {
                        overAllSize += mp[it];
                    }
                    maxArea = max(maxArea, overAllSize);
                }
            }
        }

        return maxArea;
    }
};