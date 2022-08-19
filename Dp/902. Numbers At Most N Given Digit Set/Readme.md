# [902. Numbers At Most N Given Digit Set](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/)

###### tags: `leetcode` `hard` `dp`

[TOC]

## Description
Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.

## Way1 - Digit dp

```cpp
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // goal: compute number of integers using digit set such that is in [1, n]
        // idea: digit dp
        // put from left to right
        // only consider bound
        // dp[i][isbound] can from dp[i+1]...
        
        string s = to_string(n);
        
        int dp[10][2][2];
        memset(dp, -1, sizeof dp);
        
        auto dfs = [&](const auto &self, int i, bool isbound=true, bool leading_zero=true) {
            if (i == s.size()) return (int)!leading_zero;    
            
            int &res = dp[i][isbound][leading_zero];
            if (res != -1) return res; // memo
            
            res = 0;
            if (leading_zero) // skip this bit, if is first
                res += self(self, i+1, false, leading_zero);
            
            if (isbound) {
                for (auto& d: digits) {
                    if (d[0] > s[i]) continue; // too big
                    bool nbound = isbound && d[0] == s[i];
                    res += self(self, i+1, nbound, false);
                }
            }
            else { // no need to consider, all are possible
                res += digits.size()*self(self, i+1, false, false);
            }
            
            return res;
        };
        
        return dfs(dfs, 0);
    }
};
```

## Way2 - Math

> enumerate from left to right

> so first sum < length n possible.
> 
> and from leftmost to right.
> compute. and if can not have same digit. no need to compute remain.
> 
> e.g. 100. digits = {1, 3, 5}.
> 
> so first compute. xx + x. 3^2 + 3^1
> 
> and fix 1xx. and has same but no need to add.
> 
> 10x. no and return.


```cpp
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // goal: compute number of integers using digit set such that is in [1, n]
        // idea: digit counting + math
        
        string s = to_string(n);
        
        int ds = digits.size();
        int len = s.size();
        
        int res = 0;
        for (int l = 1; l < len; ++l)
            res += pow(ds, l);
        
        // consider the same length
        for (int i = 0; i < len; ++i) {
            bool same = false;
            for (auto &d: digits) {
                if (d[0] < s[i])
                    res += pow(ds, len-i-1);
                else if (d[0] == s[i])
                    same = true;
            }
            if (!same) return res;
        }
        
        return res+1; // all are same, add self
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(log10(n)\*d) | O(log10(n)) |
| Way2 | O(log10(n)) | O(1) |

