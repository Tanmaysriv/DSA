class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag;

        // Collect elements by diagonal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diag[i - j].push_back(grid[i][j]);
            }
        }

        // Sort each diagonal accordingly
        for (auto &p : diag) {
            if (p.first >= 0) {
                // bottom-left including main diagonal → descending
                sort(p.second.begin(), p.second.end(), greater<int>());
            } else {
                // top-right → ascending
                sort(p.second.begin(), p.second.end());
            }
        }

        // Refill the matrix
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = diag[i - j][idx[i - j]++];
            }
        }

        return grid;
    }
};
