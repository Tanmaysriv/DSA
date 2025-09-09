class Solution {
public:
    int compress(vector<char>& chars) {
        int j{},i{};
        int n=chars.size();
        while(i<chars.size())
        {
            char ch = chars[i];
            int cnt = 0;
            while((i<n) && (chars[i]==ch))
            {
                cnt++;
                i++;
            }
            if(cnt==1)
            {
                chars[j]=ch;
                j++;
            }
            else{
                chars[j]=ch;
                j++;
                string temp = to_string(cnt);
                for(int k =0 ;k<temp.size();k++)
                {
                    chars[j++]=temp[k];

                }
            }
            

        }
        return j;
        
    }
};