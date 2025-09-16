class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, zeroes = 0, maxlen = 0;

        while (r < n) {
            if (nums[r] == 0) zeroes++;

            // If window has more than k zeros, shrink from the left
            while (zeroes > k) {
                if (nums[l] == 0) zeroes--;
                l++;
            }

            // Update max length of valid window
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};