class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // goal: find the largest size of combination that bitwise > zero
        // idea: for each bit, calculate the nubmer that have that bit
        // O(log32*n)
        
        int res = 0;
        for (int i = 0; i < 31; ++i) { // find the maximum nubmer of candidate that have pow(2, i) bit -> bitwise and > 0
            int num = 0;
            for (auto &x: candidates) {
                num += x >> i & 1;
            }
            res = max(res, num);
        }
        return res;
    }
};
