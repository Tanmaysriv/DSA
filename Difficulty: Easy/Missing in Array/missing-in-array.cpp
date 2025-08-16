class Solution {
public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
        int xorAll = 0, xorArr = 0;

        // XOR of 1 to n
        for (int i = 1; i <= n; i++) xorAll ^= i;

        // XOR of array elements
        for (int x : arr) xorArr ^= x;

        // missing number
        return xorAll ^ xorArr;
    }
};
