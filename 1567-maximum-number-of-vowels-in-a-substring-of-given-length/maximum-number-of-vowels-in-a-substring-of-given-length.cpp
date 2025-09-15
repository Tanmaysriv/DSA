class Solution {
public:
    bool isvowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;

        return false;
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int ans=0;
        int cnt=0;
        
        //process first window
        for(int i=0;i<k;i++)
        {
            if(isvowel(s[i]))
            {
                cnt++;
            }
        }
        ans=max(ans,cnt);
        if(ans==k)
        return ans;
        //before checking for rem window first remove last char from cnt if it is vowel
        if(isvowel(s[0]))
        cnt--;
        //rem window
        for(int i=k;i<n;i++)
        {
            if(isvowel(s[i]))
            cnt++;
            ans=max(ans,cnt);
            
            //now remove last char
            if(isvowel(s[i-k+1]))
            cnt--;
        }
        return ans;
    }
};