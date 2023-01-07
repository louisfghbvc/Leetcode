# [1014. Best Sightseeing Pair](https://leetcode.com/problems/best-sightseeing-pair/description/)

###### tags: `leetcode` `medium` `dp`

[TOC]

## Description
X

## Way1 - Dp, Record maximum

```cpp
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // goal: calculate the maximum score of pair
        // val[i]+val[j]+i-j, i<j
        // val[i]+i + val[j]-j
        // idea: do from right to left
        // record the maximum val[j]-j

        int n = values.size();
        int best = values[n-1]-(n-1);
        int ans = INT_MIN;
        for (int i = n-2; i >= 0; --i) {
            ans = max(ans, values[i]+i + best);
            best = max(best, values[i]-i);
        }

        return ans;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n) | O(1) |
