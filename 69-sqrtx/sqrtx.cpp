class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; // Base cases

        int s = 1, e = x, mid;
        while (s <= e) {
            mid = s + (e - s) / 2;

            if (mid == x / mid) return mid; // Perfect square found
            else if (mid > x / mid)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return e; // e will be floor(sqrt(x))
    }
};