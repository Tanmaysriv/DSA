class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort in descending order
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        
        int i = 0, j = 0;
        int hz = 1, vt = 1;  // initial segments
        long long cost = 0;

        while (i < x.size() && j < y.size()) {
            if (x[i] > y[j]) {
                cost += (long long)x[i] * hz;
                vt++;
                i++;
            } else {
                cost += (long long)y[j] * vt;
                hz++;
                j++;
            }
        }

        // Remaining vertical cuts
        while (i < x.size()) {
            cost += (long long)x[i] * hz;
            vt++;
            i++;
        }

        // Remaining horizontal cuts
        while (j < y.size()) {
            cost += (long long)y[j] * vt;
            hz++;
            j++;
        }

        return (int)cost;
    }
};
