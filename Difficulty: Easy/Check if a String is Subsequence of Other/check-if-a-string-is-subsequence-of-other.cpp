class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        int i = 0, j = 0;
        int n = s1.size(), m = s2.size();
        
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        
        return (i == n); // if all characters of s1 are matched in s2
    }
};
