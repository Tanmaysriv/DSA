class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;  // Already at the end
        if (arr[0] == 0) return -1;  // Can't move anywhere

        int maxReach = arr[0];  // Max index we can reach
        int steps = arr[0];     // Steps we can still take
        int jumps = 1;          // At least one jump

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;  // Reached end

            maxReach = max(maxReach, i + arr[i]);
            steps--;

            if (steps == 0) {
                jumps++;
                if (i >= maxReach) return -1; // Can't move forward
                steps = maxReach - i;
            }
        }
        return -1;
    }
};
