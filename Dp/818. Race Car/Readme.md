# [818. Race Car](https://leetcode.com/problems/race-car/)

###### tags: `leetcode` `hard` `dp`

[TOC]

## Description
Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):

When you get an instruction 'A', your car does the following:
position += speed
speed *= 2
When you get an instruction 'R', your car does the following:
If your speed is positive then speed = -1
otherwise speed = 1
Your position stays the same.
For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.

Given a target position target, return the length of the shortest sequence of instructions to get there.

## Way1 - DP

3 case

```cpp
class Solution {
public:
    vector<int> dp;
    
    int racecar(int target) {
        // goal: find minimum operations that reach target
        // idea: dp[i]: minimum operations to reach i
        // either best case
        // n steps -> 2^n - 1 == target
        // case2, try to exceed and back
        // ----------->
        //       <-----
        // case3, we can n-1 steps, and get back
        // ----->
        //.   <--
        //.(  )---->
        
        dp = vector<int>(target+1);
        return dfs(target);
    }
    
    int dfs(int x) {
        int &res = dp[x];
        if (res) return res;

        int n = ceil(log2(x+1));
        // best case
        if ((1 << n) == x + 1) return res = n;
        
        // case2
        res = n + 1 + dfs((1 << n) - 1 - x);
        // case3
        for (int m = 0; m < n-1; ++m) {
            int cur = (1<<(n-1)) - (1<<m); // both have -1
            res = min(res, n - 1 + 1 + m + 1 + dfs(x - cur));
        }
        
        return res;
    }
};
```

## Way2 - BFS + Prune

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(tlogt) | O(t) |
| Way2 | O(?) | O(?) |

