class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minRow = n, maxRow = -1, minCol = m, maxCol = -1;

        // Find boundaries of all 1's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        if (maxRow == -1) return 0; // no 1's in the grid

        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;

        return height * width;
    }
};
