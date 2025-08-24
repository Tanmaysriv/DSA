// User function template for C++
class Solution {
  public:
    int search(int n, int arr[]) {
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(auto it : mp)
        {
            if(it.second==1)
            {
                return it.first;
            }
        }
        return -1;
    }
};