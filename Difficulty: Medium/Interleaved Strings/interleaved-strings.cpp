class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        function<int(int,int)>f=[&](int i,int j)->int{
            
            int k = i+j;
            
            if(i==n1 && j==n2 && k==n3)
            return 1;
            
           if(dp[i][j]!=-1)
           return dp[i][j];
           int res=0;
           if(i<n1 && s1[i]==s3[k])
           {
               int x = f(i+1,j);
               res= res | x;
           }
           
           if(j<n2 && s2[j]==s3[k])
           {
               int y= f(i,j+1);
               res = res | y;
           }
           
           return dp[i][j] = res;
        };
        return f(0,0);
    }
};