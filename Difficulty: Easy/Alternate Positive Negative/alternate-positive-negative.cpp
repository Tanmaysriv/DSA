class Solution {
public:
    void rearrange(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Partition positives and negatives separately (stable partitioning idea)
        vector<int> pos, neg;
        for (int x : arr) {
            if (x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }

        // Step 2: Merge alternately, always start with positive
        int i = 0, j = 0, k = 0;
        while (i < pos.size() && j < neg.size()) {
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }

        // Step 3: Append remaining
        while (i < pos.size()) arr[k++] = pos[i++];
        while (j < neg.size()) arr[k++] = neg[j++];
    }
};
