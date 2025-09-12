class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int left=0;
        int right=n-1;
        int flag=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(letters[mid]>target)
            {
                flag=mid;
                right=mid-1;

            }
            else
            {
                left=mid+1;
            }
        }
        return flag==-1 ? letters[0]:letters[flag];
    }
};