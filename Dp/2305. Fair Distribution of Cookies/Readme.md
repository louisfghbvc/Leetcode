# [2305. Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies/)

###### tags: `leetcode` `medium` `backtracking`

[TOC]

## Description
You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

Return the minimum unfairness of all distributions.

## Way1 - Backtracking + Prune

```cpp
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        // goal: distribute cookies to k children
        // idea: backtracking + prune
        
        sort(cookies.rbegin(), cookies.rend());
        vector<int> cols(k);
        
        int res = INT_MAX;
        
        auto dfs = [&](const auto &self, int i, int mx) -> void {
            if (mx >= res) return;
            if (i == cookies.size()) {
                res = min(res, mx);
                return;
            }
            
            unordered_set<int> vis;
            for (int j = 0; j < k; ++j) {
                if (vis.insert(cols[j]).second) {
                    cols[j] += cookies[i];
                    self(self, i+1, max(mx, cols[j]));
                    cols[j] -= cookies[i];
                }
            }
        };
        
        dfs(dfs, 0, 0);
        
        return res;
    }
};
```

## Way2 - Dp

```cpp
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
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(k^cookies) | O(k) |
