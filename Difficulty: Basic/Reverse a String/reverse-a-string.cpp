// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        int n=s.size();
        reverse(s.begin(),s.end());
        return s;
    }
};
