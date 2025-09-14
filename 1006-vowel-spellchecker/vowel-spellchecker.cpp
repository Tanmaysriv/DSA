class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;
        
        auto maskVowels = [](string s) {
            for (auto &ch : s) {
                if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') ch='*';
            }
            return s;
        };
        
        for (auto &word : wordlist) {
            string lower = word;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            
            if (!caseInsensitive.count(lower)) caseInsensitive[lower] = word;
            if (!vowelInsensitive.count(maskVowels(lower))) vowelInsensitive[maskVowels(lower)] = word;
        }
        
        vector<string> result;
        for (auto &q : queries) {
            if (exact.count(q)) {
                result.push_back(q);
                continue;
            }
            
            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            
            if (caseInsensitive.count(lower)) {
                result.push_back(caseInsensitive[lower]);
                continue;
            }
            
            if (vowelInsensitive.count(maskVowels(lower))) {
                result.push_back(vowelInsensitive[maskVowels(lower)]);
                continue;
            }
            
            result.push_back("");
        }
        
        return result;
    }
};
