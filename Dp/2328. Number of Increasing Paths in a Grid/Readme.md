# [2328. Number of Increasing Paths in a Grid](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/)

###### tags: `leetcode` `hard` `dp`

[TOC]

## Description
You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 10^9 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

## Way1 - Top Down + Dp

> We must from smallest traverse to largest
> and dfs can do that easily
> dp[i][j]: number of ways starting at (i, j)
> dp[i][j] gather from all greater number of ways

```cpp
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        // goal: find the number of lis in the grid
        // idea: dp[i][j]: number of ways that starting in (i, j)
        
        int m = grid.size(), n = grid[0].size();
        
        vector dp(m, vector(n, -1));
        const int mod = 1e9+7;
        
        auto dfs = [&](auto &self, int i, int j) {
            int &res = dp[i][j]; 
            if (res != -1) return res;
            
            res = 1; // not add anything
            for (auto &[ni, nj] : {make_pair(i-1, j), {i+1, j}, {i, j-1}, {i, j+1}}) {
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (grid[ni][nj] > grid[i][j])
                    res = (res + self(self, ni, nj)) % mod;
            }
            
            return res;
        };
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = (res + dfs(dfs, i, j)) % mod;
            }
        }
        return res;
    }
};
```

## Way2 - Naive, Do from smallset

> Think about 1D number of ways

```cpp
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        // goal: find the number of lis in the grid
        // idea: use dp, starting from the smallest value
        // dp[i][j]: number of lis so far
        // dp[i][j] = from sum of 4 dir
        
        const int mod = 1e9+7;
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<long>> dp(m, vector<long>(n));
        
        // we need the order of traverse
        vector<vector<int>> order;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                order.push_back({grid[i][j], i, j});
        
        sort(order.begin(), order.end());
        
        for (auto &o: order) {
            int val = o[0], i = o[1], j = o[2];
            dp[i][j] = 1;
            if (i && val > grid[i-1][j]) {
                dp[i][j] += dp[i-1][j];
            }
            if (j && val > grid[i][j-1]) {
                dp[i][j] += dp[i][j-1];
            }
            if (i+1 < m && val > grid[i+1][j]) {
                dp[i][j] += dp[i+1][j];
            }
            if (j+1 < n && val > grid[i][j+1]) {
                dp[i][j] += dp[i][j+1];
            }
            dp[i][j] %= mod;
        }
        
        
        long ans = 0;
        for (auto &r: dp)
            for (auto &c: r)
                ans = (ans + c) % mod;
        
        return ans;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(mn) | O(mn) |
| Way2 | O(mnlogmn) | O(mn) |

