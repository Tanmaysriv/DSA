class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        string token;
        string ans;
        vector<string>vec;
        while(ss>>token)
        {
            vec.push_back(token);

        }   
        for(int i=vec.size()-1;i>=0;i--)
        {
            ans+= vec[i] + ' ';
        }
        return ans.substr(0,ans.size()-1);
        
     }
};