class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> heights(n, 0);
        int result = 0;

        for (int i = 0; i < m; i++) {
            // Update histogram heights
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }

            // Count submatrices ending at this row
            result += countHist(heights);
        }
        return result;
    }

    int countHist(vector<int>& heights) {
        int n = heights.size();
        vector<int> sum(n, 0);
        stack<int> st;
        int res = 0;

        for (int j = 0; j < n; j++) {
            while (!st.empty() && heights[st.top()] >= heights[j])
                st.pop();

            if (!st.empty()) {
                int prev = st.top();
                sum[j] = sum[prev] + heights[j] * (j - prev);
            } else {
                sum[j] = heights[j] * (j + 1);
            }

            st.push(j);
            res += sum[j];
        }
        return res;
    }
};
