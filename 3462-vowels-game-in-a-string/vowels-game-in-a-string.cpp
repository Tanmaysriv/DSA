class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true; // Alice can remove at least one vowel
            }
        }
        return false; // No vowels, Alice loses immediately
    }
};
