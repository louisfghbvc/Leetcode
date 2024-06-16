class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // goal: find the maximum total damage
        // idea:
        // sort the power
        // [1,1,3,4,x,...]
        //  1 1   4
        //           5
        // dfs(i) : starting from index i, maximum damage can get
        // for j > i:
        //     if (power[j] - power[i] > 2)
        //         power[i] + dfs(j) 
        // max of ()
        
        // TC: O(n^2) 
        // 1. sort
        // 2. merge the same power, record the cnt
        // 3. dp
        // dp[i]: maximum we can get, starting from index i
        //      j>i: can add max of dp[j], where power[j]-power[i] > 2
        // just maintain a maxheap, (dp[j], power[j]) 
        // when we add, 
        // dp[i] = power[i] + dp[j] => dp[i-1] = power[i-1] + dp[j] 
        
        ranges::sort(power);
        unordered_map<int, int> cnt;
        for (int x: power)
            cnt[x]++;
        power.erase(unique(power.begin(), power.end()), power.end());
        
        
        int n = power.size();
        vector<long> dp(n, 0);
        
        long ans = 0, mx = 0;
        for (int i = n-1, j = n-1; i >= 0; --i) {
            while (j > i && power[j] - power[i] > 2) {
                mx = max(mx, dp[j]);
                j--;
            } 
            dp[i] = (long)power[i] * cnt[power[i]];
            dp[i] += mx;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

// Approach 2. top down
// Basicly we need to find the X+3 position. we don't need X+4, since dp[X+3] cover dp[X+4]
// each time we will skip or not

