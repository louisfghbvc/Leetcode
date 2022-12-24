# [790. Domino and Tromino Tiling](https://leetcode.com/problems/domino-and-tromino-tiling/description/)

###### tags: `leetcode` `medium` `dp`

[TOC]

## Description


## Way1 - two DP

> 插頭(輪廓)dp
> dp2[i]: 表示長度為i但少一塊的方法數(只計算缺上或缺下就好, 因為這兩個方法數根本一樣不須分開更新)

```cpp=
class Solution {
public:
    int numTilings(int n) {
        // goal: tile a board until u        
        // idea: consider dp
        // dp[i]: number of ways length is i
        // dp2[i]: number of ways such that length is i, less one(no matter upper or lower, since the both state is same)

        // use domino tile
        // dp[i] = dp[i-1] + dp[i-2]

        if (n <= 2) return n; // base case

        vector dp(n+1, 0);
        vector dp2(n+1, 0);

        int mod = 1e9+7;

        dp[0] = dp[1] = 1; // base case
        for (int i = 2; i <= n; ++i) {
            // use domino
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
            // use trimino
            dp[i] = (dp[i] + 2*dp2[i-1]%mod) % mod;

            // update dp2
            dp2[i] = (dp2[i-1] + dp[i-2]) % mod;
        }

        return dp[n];
    }
};

// domino tile
// dp[i] = dp[i-1]+dp[i-2]
// 1.
// (x x x x x) x
//             a
//             a
// 2.
// (x x x x) x x  
//           a a
//           b b 
// dp[i] = 2*dp2[i-1]
// 1.
// x x x x x x a a
// x x x x x x x a
// 2.
// x x x x x x x a
// x x x x x x a a

// dp2[i] = dp2[i-1] (put a domino)
// x x a a 
// x x x

// dp2[i] = dp[i-2] (put a tromino)
// x x a a
// x x a 
```

## Appendix
https://hackmd.io/Du0IHEqDT8yqmI74koDZZw#%E8%BC%AA%E5%BB%93DP

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n) | O(n) |
