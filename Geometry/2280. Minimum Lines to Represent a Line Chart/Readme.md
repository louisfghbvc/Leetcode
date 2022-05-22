# [2280. Minimum Lines to Represent a Line Chart](https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/)

###### tags: `leetcode` `medium` `two pointers` `geometry`

[TOC]

## Description
Find the minimum line that can connect all stock points

## Way1 - Two Pointers

```c++
class Solution {
public:
    
    pair<int, int> getSlope(vector<int> &a, vector<int> &b) {
        return {b[1] - a[1], b[0] - a[0]};
    }
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        // goal: calculate the number of distinct lines
        // idea: calculate the adjcacent different slopes, we should sort by days
                
        int n = stockPrices.size();
        sort(stockPrices.begin(), stockPrices.end());
         
        vector<pair<int, int>> slopes;
        for (int i = 0; i+1 < n; ++i) {
            slopes.push_back(getSlope(stockPrices[i], stockPrices[i+1]));
        }
        
        int res = 0; // lines
        for (int i = 0, j; i < slopes.size(); i = j) {
            j = i;
            while (j < slopes.size() && 1LL * slopes[i].first * slopes[j].second == 1LL * slopes[i].second * slopes[j].first) { // dy*djx = djy*dx ->  same
                j++;
            }
            if (j == i) j++;
            res++;
        }
        
        return res;
    }
};
```

## Way2 - In place

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(nlogn) | O(n) |
| Way2 | O(nlogn) | O(1) |
