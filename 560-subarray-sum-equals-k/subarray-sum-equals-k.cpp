class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> freq;
        freq[0] = 1; // base case: empty prefix

        long long sum = 0;
        int count = 0;

        for (int num : nums) {
            sum += num;

            if (freq.find(sum - k) != freq.end()) {
                count += freq[sum - k];
            }

            freq[sum]++;
        }

        return count;
    }
};
