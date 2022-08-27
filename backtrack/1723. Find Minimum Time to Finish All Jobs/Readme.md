# [1723. Find Minimum Time to Finish All Jobs](https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/)

###### tags: `leetcode` `hard` `backtracking` `dp`

[TOC]

## Description


## Way1 - Backtracking

> sort從大到小的話，能夠省去很多小的拼成大的狀況
> 重複的worker不用做
> 現在最大值明顯比答案大，不用做

```cpp
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        // goal: sperate job to k workers
        // minimized the maximum work time
        
        // constraint of jobs and k is small
        // idea3:
        
        sort(jobs.rbegin(), jobs.rend());
            
        int n = jobs.size();
        vector<int> cols(k);
        
        int ans = 1e9;
        
        auto dfs = [&](const auto &self, int i, int mx) -> void {
            if (mx >= ans) return; // no need, prune
            if (i == n) {
                ans = min(mx, ans);
                return;
            }
            
            unordered_set<int> st;
            for (int j = 0; j < k; ++j) {
                // can insert
                if (st.insert(cols[j]).second) {
                    cols[j] += jobs[i];
                    self(self, i+1, max(mx, cols[j]));
                    cols[j] -= jobs[i];
                }
            }    
        };
        
        dfs(dfs, 0, 0);
        
        return ans;
    }
};
```

## Way2 - Dp

put person one by one
try all combination

```cpp
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        // goal: sperate job to k workers
        // minimized the maximum work time
        
        // constraint of jobs and k is small
        // idea:
        // each subset has a worker
        // dp[i][mask]: current mask use i workers, minimum time
            
        int n = jobs.size();
        
        // initialize
        vector dp(k+1, vector(1<<n, 1e9));
        for (int m = 0; m < 1<<n; ++m) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (m >> i & 1)
                    sum += jobs[i];
            }
            dp[1][m] = sum;
        }

        for (int i = 2; i <= k; ++i) {
            for (int m = 0; m < 1<<n; ++m) {
                for (int subMask = m; subMask; subMask = (subMask-1) & m)
                    dp[i][m] = min(max(dp[1][subMask], dp[i-1][subMask^m]), dp[i][m]);
            }
        }
        
        return dp[k].back();
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(k^n) | O(n+k) |
| Way2 | O(k3^n) | O(n\*k) |
