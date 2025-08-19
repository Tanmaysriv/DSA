class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, streak = 0;

        for (int num : nums) {
            if (num == 0) {
                streak++;          // extend the current zero streak
                count += streak;   // add subarrays ending at this position
            } else {
                streak = 0;        // reset streak when non-zero appears
            }
        }

        return count;
    }
};
