class Solution {
public:

    int firstOccurence(vector<int>nums,int target)
    {
        int left=0;
        int right=nums.size()-1;
        int ans=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>=target)
            {
                right=mid-1;
            }
             else
            {
                left=mid+1;
            }
            if(nums[mid]==target)
            {
                ans=mid;
            }
           
        }
        return ans;
    }

    int secondOccurence(vector<int>nums,int target)
    {
        int left=0;
        int right=nums.size()-1;
        int ans=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]<=target)
            {
                left=mid+1;
            }
             else
            {
                right=mid-1;
            }
            if(nums[mid]==target)
            {
                ans=mid;
            }
           
        }
        return ans;
    }
   
    vector<int> searchRange(vector<int>& nums, int target) {
        return{firstOccurence(nums,target),secondOccurence(nums,target)};
        
    }
};