class Solution {
public:
    int minBitFlips(int start, int goal) {
        // goal: flip start to goal
        return __builtin_popcount(start ^ goal);
    }
};
