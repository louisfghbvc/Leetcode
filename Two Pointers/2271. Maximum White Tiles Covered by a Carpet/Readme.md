# [2271. Maximum White Tiles Covered by a Carpet](https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/)

###### tags: `leetcode` `medium` `two pointers` `binary search`

[TOC]

## Description
Find the maximum white tiles that can cover by a carpet.

## Way1 - Sliding window
Always can get the best ans from each left segment.

```c++
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        // goal: only use one carpet that can cover 
        // idea: use two pointers -> sliding window
        // sort the array
        
        sort(tiles.begin(), tiles.end());
        
        int n = tiles.size();
        
        int ans = 0;
        int number_whites = 0;
        
        for (int r = 0, l = 0; r < n && ans < carpetLen; ++r) {
            while (l <= r && tiles[l][0] + carpetLen <= tiles[r][1]) { // too much
                int partial = max(0, tiles[l][0] + carpetLen - tiles[r][0]);
                ans = max(number_whites + partial, ans);
                number_whites -= tiles[l][1] - tiles[l][0] + 1;
                l++;
            }
            number_whites += tiles[r][1] - tiles[r][0] + 1;
            ans = max(ans, number_whites);
        }
        
        return ans;
    }
};
```

## Way2 - Binary Search + prefix sum

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(nlogn) | O(n) |
| Way2 | O(nlogn) | O(n) |
