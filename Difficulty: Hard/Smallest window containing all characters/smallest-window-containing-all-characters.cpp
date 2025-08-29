class Solution {
public:
    string smallestWindow(string &s, string &p) {
        if (s.size() < p.size()) return "";

        // Frequency maps
        vector<int> freqP(256, 0), freqS(256, 0);

        // Count frequency of characters in p
        for (char c : p) freqP[c]++;

        int start = 0, minLen = INT_MAX, startIdx = -1;
        int count = 0;  // To keep track of matched characters

        for (int end = 0; end < s.size(); end++) {
            // Include current character in window
            freqS[s[end]]++;

            // If current char is part of p and count <= freq in p
            if (freqP[s[end]] != 0 && freqS[s[end]] <= freqP[s[end]]) {
                count++;
            }

            // If all characters are matched
            if (count == p.size()) {
                // Shrink the window
                while (freqS[s[start]] > freqP[s[start]] || freqP[s[start]] == 0) {
                    if (freqS[s[start]] > freqP[s[start]]) {
                        freqS[s[start]]--;
                    }
                    start++;
                }

                int windowLen = end - start + 1;
                if (windowLen < minLen) {
                    minLen = windowLen;
                    startIdx = start;
                }
            }
        }

        if (startIdx == -1) return "";
        return s.substr(startIdx, minLen);
    }
};
