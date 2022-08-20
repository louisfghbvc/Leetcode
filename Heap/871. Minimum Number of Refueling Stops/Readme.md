# [871. Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/)

###### tags: `leetcode` `hard` `dp` `greedy` `heap`

[TOC]

## Description

## Way1 - Heap + Greedy

```cpp
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // goal: use minimum refuel to reach target
        // idea: 
        // greedy, use maximum fuel we can reach
        // use a max-heap
        
        priority_queue<int> pq;
        
        int i = 0; // stations index
        int cnt = 0;
        while (startFuel < target) {
            while (i < stations.size() && stations[i][0] <= startFuel) {
                pq.push(stations[i][1]);
                i++;
            }
            
            if (pq.empty()) return -1;
            startFuel += pq.top(); pq.pop();
            cnt++;
        }
        
        return cnt;
    }
};
```


## Way2 - Dp

> from N^2 to optimized
> dp[i][j]: first i stations use j stations
> dp[i][j]: dp[i-1][j-1] + stations[i][1], j=0~i

```cpp
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // goal: use minimum refuel to reach target
        // idea: 
        // dp[i]: maximum position can reach by using first i stations
        // dp[i] = 
        
        int n = stations.size();
        vector dp(n+1, 0L);
        
        dp[0] = startFuel;
        for (int i = 0; i < n; ++i) {
            for (int k = i; k >= 0; --k) {
                if (dp[k] >= stations[i][0])
                    dp[k+1] = max(dp[k+1], dp[k] + stations[i][1]);
            }
        }
        
        for (int i = 0; i <= n; ++i) {
            if (dp[i] >= target) return i;
        }
        
        return -1;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(nlogn) | O(n) |
| Way2 | O(n^2) | O(n) |

