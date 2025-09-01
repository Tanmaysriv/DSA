#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq;
        map<int,set<int>> freqMap; // frequency -> set of numbers
        int sum = 0;

        auto add = [&](int x) {
            int oldFreq = freq[x];
            if(oldFreq > 0) {
                freqMap[oldFreq].erase(x);
                if(freqMap[oldFreq].empty()) freqMap.erase(oldFreq);
            }
            freq[x]++;
            freqMap[freq[x]].insert(x);
        };

        auto remove = [&](int x) {
            int oldFreq = freq[x];
            freqMap[oldFreq].erase(x);
            if(freqMap[oldFreq].empty()) freqMap.erase(oldFreq);
            freq[x]--;
            if(freq[x] > 0) {
                freqMap[freq[x]].insert(x);
            }
        };

        // build first window
        for(int i=0; i<k; i++) add(arr[i]);
        sum += *freqMap.rbegin()->second.begin(); // mode of first window

        // slide window
        for(int i=k; i<n; i++) {
            add(arr[i]);
            remove(arr[i-k]);
            sum += *freqMap.rbegin()->second.begin(); // mode
        }

        return sum;
    }
};