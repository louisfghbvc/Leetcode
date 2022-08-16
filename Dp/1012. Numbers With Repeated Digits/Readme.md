# [1012. Numbers With Repeated Digits](https://leetcode.com/problems/numbers-with-repeated-digits/)

###### tags: `leetcode` `hard` `dp`

[TOC]

## Description
Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.

## Way1 - Digit dp

```cpp
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        // goal: find the number that have duplicate digit
        // idea: calculate the number that has single digit
        
        int dp[10][1<<10][2][2];
        memset(dp, -1, sizeof dp);
        
        string s = to_string(n);
        
        auto dfs = [&](const auto &self, int i, int mask, bool isbound=true, bool leading_zero=true) -> int {
            if (i == s.size()) return !leading_zero; // base case
            
            int &res = dp[i][mask][isbound][leading_zero];
            if (res != -1) return res;
            
            res = 0;
            int bd = isbound ? s[i]-'0' : 9;
            for (int d = 0; d <= bd; ++d) {
                if (mask >> d & 1) continue;
                bool nlz = leading_zero && d == 0;
                bool nbound = isbound && d == s[i]-'0';
                int nmask = nlz ? 0 : mask|(1<<d);
                res += self(self, i+1, nmask, nbound, nlz);
            }
            
            return res;
        };
        
        
        return n - dfs(dfs, 0, 0);
    }
};
```

## Way2 - Backtracking

```cpp
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        // goal: find the number that have duplicate digit
        // idea: calculate the number that has single digit
        
        int unique_num = 0;
        
        auto dfs = [&](const auto &self, long val, int mask) {
            if (val > n) return;
            unique_num++;
            
            for (int d = 0; d <= 9; ++d) {
                if (d == 0 && mask == 0) continue; // zero
                if (mask >> d & 1) continue;
                self(self, val*10+d, mask|(1<<d));
            }
        };
        
        dfs(dfs, 0, 0);
        
        return n - unique_num + 1;
    }
};
``

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(log10(n)\*2^d\*d) | O(log10(n)\*2^d) |
| Way2 | O(9!) | O(n) |

