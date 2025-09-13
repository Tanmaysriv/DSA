class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        unordered_set<char> vowels = {'a','e','i','o','u'};
        int maxVowel = 0, maxConsonant = 0;

        for (auto &p : freq) {
            if (vowels.count(p.first)) {
                maxVowel = max(maxVowel, p.second);
            } else {
                maxConsonant = max(maxConsonant, p.second);
            }
        }

        return maxVowel + maxConsonant;
    }
};
