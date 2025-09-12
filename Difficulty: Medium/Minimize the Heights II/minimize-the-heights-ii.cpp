class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;

        sort(arr.begin(), arr.end());

        int ans = arr[n-1] - arr[0];  // Initial difference

        for (int i = 0; i < n - 1; i++) {
            int minHeight = min(arr[0] + k, arr[i+1] - k);
            int maxHeight = max(arr[i] + k, arr[n-1] - k);

            if (minHeight < 0) continue;  // skip invalid case

            ans = min(ans, maxHeight - minHeight);
        }

        return ans;
    }
};
