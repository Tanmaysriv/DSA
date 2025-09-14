class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        int n= nums.size();
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }

        double ans= sum;
        for(int i=k;i<n;i++)
        {
            sum+=nums[i]-nums[i-k];
            ans=max(ans,sum);
        }
        return ans/k;

        
    }
};