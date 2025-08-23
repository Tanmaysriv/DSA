class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int cnt1=0;
        int maxi1=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==1)
            {
                cnt1++;
                maxi1=max(maxi1,cnt1);
            }
            else
            {
                cnt1=0;
            }
        }
        int cnt2=0;
        int maxi2=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                cnt2++;
                maxi2=max(maxi2,cnt2);
            }
            else
            {
                cnt2=0;
            }
        }
        if(maxi1>maxi2)
        {
            return maxi1;
        }
        else
        {
            return maxi2;
        }
    }
};