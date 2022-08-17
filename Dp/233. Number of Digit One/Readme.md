# [233. Number of Digit One](https://leetcode.com/problems/number-of-digit-one/)

###### tags: `leetcode` `hard` `dp`

[TOC]

## Description
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

## Way1 - digit dp

> from backtracking to simply
```cpp
class Solution {
public:
    int countDigitOne(int n) {
        // goal: find the number of digit 1 in [1, n]
        
        // 13
        // 1, 10, 11, 12, 13
        // idea: use digit dp
        // dp[i][number of 1]: isbound ? d=0..bound, sum of dp[i+1][number of 1]
        // dfs(i, int one)
        //      if i == d.len: return one
        // ...
        
        string s = to_string(n);
        
        int dp[10][10][2][2];
        memset(dp, -1, sizeof dp);
        
        auto dfs = [&](const auto &self, int i, int one, bool isbound=true, bool leading_zero=true) {
            if (i == s.size()) return one;
            
            int &res = dp[i][one][isbound][leading_zero];
            if (res != -1) return res; // memo
            
            res = 0; // number of 1
            int bd = isbound ? s[i]-'0' : 9;
            for (int d = 0; d <= bd; ++d) {
                bool nbound = isbound && d == s[i]-'0';
                bool nlz = leading_zero && d == 0; 
                res += self(self, i+1, one+(d==1), nbound, nlz);
            } 
            
            return res;
        };
        
        return dfs(dfs, 0, 0);
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(log10(n)^2\*d) | O(log10(n)^2) |
