class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int totsum=n*(n+1)/2;
        int sum=0;
        for(auto it : nums)
        {
            sum+=it;
        }
        return totsum-sum;
    }
};