class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        vector<int> last(10, -1); 
        
        // store last occurrence of each digit
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }

        // traverse and find the first place we can swap
        for (int i = 0; i < n; i++) {
            // check from '9' to s[i]+1
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    // swap with rightmost bigger digit
                    swap(s[i], s[last[d]]);
                    return s;
                }
            }
        }
        
        return s; // already the largest
    }
};
