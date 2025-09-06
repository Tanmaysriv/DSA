class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        // Precompute powers of 4
        vector<long long> pow4;
        pow4.push_back(1);
        while (pow4.back() <= 1e9) {
            pow4.push_back(pow4.back() * 4);
        }

        long long ans = 0;

        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long totalSteps = 0;

            for (int k = 1; k < pow4.size(); k++) {
                long long left = max(l, pow4[k - 1]);
                long long right = min(r, pow4[k] - 1);

                if (left <= right) {
                    long long cnt = right - left + 1;
                    totalSteps += cnt * k;
                }
            }

            ans += (totalSteps + 1) / 2; // ceil division
        }

        return ans;
    }
};
