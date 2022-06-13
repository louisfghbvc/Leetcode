// dp + mask O(k*3^n)

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        // goal: split cookies to k children. get minimize the maximum of a single children can get
        // idea: dp
        // for each child calculate the bitmask sum of cookies
        
        int n = cookies.size();
        
        // O(n2^n)
        vector<int> cookieSum(1<<n);
        for (int mask = 0; mask < 1<<n; ++mask) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1)
                    sum += cookies[i];
            }
            cookieSum[mask] = sum;
        }
        
        
        vector<vector<int>> dp(k+1, vector<int>(1<<n, INT_MAX));
        dp[0][0] = 0;
        
        // O(k*3^n)
        for (int i = 1; i <= k; ++i) {
            for (int mask = 0; mask < 1<<n; ++mask) {
                for (int subMask = mask; subMask; subMask = (subMask-1) & mask) {
                    dp[i][mask] = min(dp[i][mask], max(dp[i-1][subMask ^ mask], cookieSum[subMask]));
                }
            }
        }
        
        return dp[k].back();
    }
};

// backtracking
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        // O(8^8) = (2^24)
        // goal: split cookies to k children. get minimize the maximum of a single children can get
        // idea: dfs
        
        int ans = INT_MAX;
        
        vector<int> child(k);
        
        // ith cookie to jth child
        auto dfs = [&](const auto &self, int i) -> void {
            if (i == cookies.size()) {
                ans = min(ans, *max_element(child.begin(), child.end()));
                return;
            }
            
            for (int j = 0; j < k; j++) {
                child[j] += cookies[i];
                self(self, i+1);
                child[j] -= cookies[i]; 
            }
        };
        
        dfs(dfs, 0);
        return ans;
    }
};
