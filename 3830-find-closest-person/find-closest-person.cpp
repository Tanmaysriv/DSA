class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = abs(x - z);  // distance of Person 1 to Person 3
        int d2 = abs(y - z);  // distance of Person 2 to Person 3

        if (d1 < d2) return 1;   // Person 1 reaches first
        if (d2 < d1) return 2;   // Person 2 reaches first
        return 0;                // both reach at the same time
    }
};
