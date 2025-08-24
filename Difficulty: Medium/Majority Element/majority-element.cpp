class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(auto it: mp)
        {
            if(it.second>n/2)
            {
                return it.first;
            }
        }
        return -1;
    }
};