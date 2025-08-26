class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0;
        int maxArea = 0;

        for (auto &rect : dimensions) {
            int length = rect[0];
            int width = rect[1];

            // Diagonal length (without sqrt to avoid precision issues, compare squares)
            long long diagSq = 1LL * length * length + 1LL * width * width;
            int area = length * width;

            if (diagSq > maxDiagonal) {
                maxDiagonal = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiagonal) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
