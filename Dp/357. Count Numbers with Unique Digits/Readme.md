# [357. Count Numbers with Unique Digits](https://leetcode.com/problems/count-numbers-with-unique-digits/)

###### tags: `leetcode` `medium` `dp` `math`

[TOC]

## Description
Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10^n.

## Way1 - Digit dp

```cpp
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // goal: count numbers where number has unique digit
        // idea: 
        // digit dp
        // calculate from highest bit to lowest
        // dp[i][mask]: number that has unique digit, length is i
        // mask: the digit we use
        
        vector dp(n+1, vector(1<<10, vector(2, -1)));
        
        auto dfs = [&](const auto &self, int i, int mask, bool leading_zero=true) {
            if (i == 0) return 1; // base case
            
            int &res = dp[i][mask][leading_zero];
            if (res != -1) return res;
            
            res = 0;
            for (int d = 0; d <= 9; ++d) {
                if (mask >> d & 1) continue; // same digit
                bool nlz = leading_zero && d == 0;
                int nmask = nlz ? 0 : mask|(1<<d);
                res += self(self, i-1, nmask, nlz);
            }
            return res;
        };
        
        return dfs(dfs, n, 0);
    }
};
```

## Way2 - Backtracking

```cpp
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // goal: count numbers where number has unique digit
        // idea: 
        // backtracking
        // starting from lowest digit to highest
        
        int res = 1;
        auto dfs = [&](const auto &self, int i, int mask) {
            if (i == n) return;
            
            for (int d = i == 0 ? 1 : 0; d <= 9; ++d) {
                if (mask >> d & 1) continue;
                res++;
                self(self, i+1, mask|(1<<d));
            }
        };
        
        dfs(dfs, 0, 0);
        return res;
    }
};
```


## Way3 - Math

```cpp
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // goal: count numbers where number has unique digit
        // idea: 
        // combination
        

        if (n == 0) return 1;
        if (n == 1) return 10;
        
        // 10+9*9+(9*9*8)+....
        
        int res = 10;
        int product = 9;
        int d = 9;
        for (int i = 1; i < n; ++i) {
            product *= d;
            d--;
            res += product;
        }
        
        return res;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n\*2^10) | O(n\*2^10) |
| Way2 | O(9!/n!) | O(n) |
| Way3 | O(n) | O(1) |


