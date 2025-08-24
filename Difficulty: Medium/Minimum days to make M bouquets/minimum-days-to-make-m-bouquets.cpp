class Solution {
public:
    bool canMake(vector<int>& arr, int k, int m, int day) {
        int count = 0, bouquets = 0;
        for (int bloom : arr) {
            if (bloom <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long n = arr.size();
        if ((long long)k * m > n) return -1; // Not enough flowers

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(arr, k, m, mid)) {
                ans = mid;
                high = mid - 1; // Try smaller day
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
