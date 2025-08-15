class Solution {
public:
    bool isPowerOfFour(int n) {
        // n must be positive
        if (n <= 0) return false;

        // Check if n is a power of two: only one bit set in binary
        if (n & (n - 1)) return false;

        // Check if the single bit is in an odd position (1, 4, 16, ...)
        return (n & 0x55555555) != 0;
    }
};
