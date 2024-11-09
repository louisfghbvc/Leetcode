class Solution {
public:
    long long minEnd(int n, int x) {
        // goal: find the array length is n, AND value is x
        // and nums[i] < nums[i+1], minimum the last value

        // idea:
        // think about x, all values at least x

        // n=3
        // x=10
        // 10 & 11 & 100 => x?
        // 10 & 11 & 110

        n--;
        vector<int> cnt(64);
        for (int i = 0; i < 32; ++i) {
            if (x >> i & 1) {
                cnt[i] = 1;
            }
        } 

        // put from last non-set bit
        int j = 0;
        while (n) {
            for (; j < 64; ++j) {
                if (cnt[j]) continue;
                cnt[j] = n%2;
                j++;
                n >>= 1;
                break;
            } 
        }

        long ans = 0;
        for (int i = 0; i < 64; ++i) {
            if (cnt[i]) {
                ans |= 1LL<<i;
            }
        }
        return ans;
    }
};
