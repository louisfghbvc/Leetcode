class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        // goal: choose one non-empty
        // idea: greed
        
        long res = 1;
        int mx = -10, mx_neg = -10;
        int neg_cnt = 0;
        for (int x: nums) {
            if (x > 0) res *= x;
            if (x < 0) {
                mx_neg = max(mx_neg, x);
                res *= x;
                neg_cnt++;
            }
            mx = max(mx, x);
        }

        if (mx == 0 && neg_cnt < 2) return 0;
        if (mx < 0 && neg_cnt == 1) return mx_neg;
        if (res > 0) return res;
        return res / mx_neg;
    }
};
