class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        int left=0;
        int right=n-1;
        int totsum=0;
        vector<pair<int,int>>res;
        for(int i=0;i<n;i++)
        {
            res.push_back({nums[i],i});
        }
        sort(res.begin(),res.end());
        while(left<right)
        {
            totsum=res[left].first+res[right].first;
            if(totsum==target)
            {
                return {res[left].second,res[right].second};
            }
            else if(totsum<target)left++;
            else right--;
        }
        return {};
        
    }
};