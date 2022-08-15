# [2376. Count Special Integers](https://leetcode.com/problems/count-special-integers/)

###### tags: `leetcode` `hard` `dp`

[TOC]

## Description
We call a positive integer special if all of its digits are distinct.

Given a positive integer n, return the number of special integers that belong to the interval [1, n].

## Way1 - digit dp

```cpp
class Solution {
public:
    int countSpecialNumbers(int n) {
        // special: all the digits are distinct
        // goal: calculate the [1, n] how many number of special value
        
        // idea: digit dp
        // TC: O(d*2^d*d) SC: O(d*2^d*d)
        
        
        string s = to_string(n);
        
        int dp[10][1<<10][2][2];
        memset(dp, -1, sizeof dp);
        
        
        auto dfs = [&](const auto &self, int i, int vis, bool isbound=true, bool leading_zero=true) -> int {
            if (i == s.size()) return !leading_zero;  // base case, 0
            
            int &res = dp[i][vis][isbound][leading_zero];
            if (res != -1) return res; // memo
            
            res = 0;
            int bd = isbound ? s[i]-'0' : 9;
            for (int d = 0; d <= bd; ++d) {
                bool nbound = isbound && d == s[i]-'0';
                bool nlz = leading_zero && d == 0;
                int nmask = nlz ? 0 : vis|(1<<d);
                if (vis >> d & 1) continue; // same digit
                res += self(self, i+1, nmask, nbound, nlz);
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
| Way1 | O(n\*2^d\*d) | O(n\*2^d) |
