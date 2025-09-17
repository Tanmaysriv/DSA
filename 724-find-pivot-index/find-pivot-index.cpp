class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ls=0,totals=0;
        int k=nums.size();
        for(int i=0;i<k;i++)
        {
            totals+=nums[i];   
        }
        for(int i=0;i<k;i++)
        {
             if(ls==totals-ls-nums[i])
            {
                return i;
            }
            ls+=nums[i];
        }
        return -1;
        
    }
};