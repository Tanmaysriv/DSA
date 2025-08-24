class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int left=0;
        int right=n-1;
        int sum=0;
        while(left<right)
        {
            sum=arr[left]+arr[right];
            if(sum==target)
            {
                return true;
            }
            else if(sum<target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return false;
    }
};