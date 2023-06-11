class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        // goal: find the total distance for each robot
        // idea:
        // d is large -> no simulate
        // cross over, no need to simulate, trick
        // sort them, just compute
        
        int n = s.size();
        vector<long> tmp(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') 
                tmp[i] += d;
            else 
                tmp[i] -= d;
        }
        
        sort(tmp.begin(), tmp.end());
        // -3,-1,1
        
        long pre = 0;
        long ans = 0;
        int mod = 1e9+7;
        for (int i = 0; i < n; ++i) {
            ans += tmp[i] * i % mod - pre;
            ans %= mod;
            if (ans < 0) ans += mod;
            pre = (pre + tmp[i]) % mod;
        }
        
        return ans;
    }
};
