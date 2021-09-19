// Sort by end position. O(NlogN).
// and we just use binary search, try to extand, since end is increasing.

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        long res = 0;
        
        sort(rides.begin(), rides.end(), [&](auto &a, auto &b){
            return a[1] < b[1];
        });
        
        map<int, long> dp{{0, 0}};
        for(auto &v: rides){
            int l = v[0], r = v[1], c = v[2];
            auto it = prev(dp.upper_bound(v[0]));
            if(it->second + r - l + c > dp.rbegin()->second){
                dp[r] = it->second + r - l + c;
            }
        }
        
        return dp.rbegin()->second;
    }
};

// Build graph O(N + M).
// From each end point, try to get the maximum. dp[i]: maximum get so far.
class Solution {
public:
    typedef pair<int, int> ii;
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        long res = 0;
        
        vector<vector<ii>> g(n+1);
        for(auto &v: rides){
            g[v[1]].push_back({v[0], v[1] - v[0] + v[2]});
        }
        
        vector<long> dp(n+1);
        for(int i = 1; i <= n; ++i){
            for(auto &[u, cost]: g[i]){
                dp[i] = max(dp[u] + cost, dp[i]);
            }
            dp[i] = max(dp[i], dp[i-1]);
        }
        
        return dp.back();
    }
};
