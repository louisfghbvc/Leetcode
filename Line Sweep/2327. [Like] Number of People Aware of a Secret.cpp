// O(N). stuck in first person should be extracted
// can not simplified in the for loop, or easier -> dp[1]=1, dp[2]=-1.
// 

class Solution {
public:
    
    const int mod = 1e9+7;
    void add(long &a, long b) {
        a = ((a + b) % mod + mod) % mod;
    }
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // goal: find the number of people known the secret in nth day
        // idea: 
        // starting from first day to last day
        
        // line sweep
        
        vector<long> dp(n+5); // new people in ith day
        
        // add x to [l, r] 
        auto apply = [&](int l, int r, long x) -> void {
            add(dp[l], x);
            add(dp[r+1], -x);
        };
        
        apply(1+delay, forget, 1);
        long flow = 0;
        long ans = 1+forget > n; // edge case, first day can live
        for (int d = 2; d <= n; ++d) {
            add(flow, dp[d]);
            apply(min(d+delay, n+1), min(d+forget-1, n+1), flow);
            if (d + forget > n) // means current flow(new people can live)
                add(ans, flow);
        }
        
        return ans;
    }
};

// Brute force
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // goal: find the number of people known the secret in nth day
        // idea: 
        // starting from first day to last day
        // line sweep problem?
        
        const int mod = 1e9+7;
        
        // why I thinking O(n) solution?
        // O(N^2)
        
        vector<long> spread(n+1);
        vector<long> dis(n+1);
        spread[1] = 1;
        long ans = 0;
        
        for (int d = 1; d <= n; ++d) {
            for (int i = d+delay; i < d+forget && i <= n; ++i) {
                spread[i] += spread[d];
                spread[i] %= mod;
            }
            if (d + forget <= n)
                dis[d + forget] -= spread[d];
            ans += spread[d] + dis[d];
            ans %= mod;
            if (ans < 0) ans += mod;
        }
        
        return ans;
    }
};
