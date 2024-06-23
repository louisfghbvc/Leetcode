# [3197. Find the Minimum Area to Cover All Ones II](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/description/)

[TOC]

## Description

## Way1 - Recursive (Divide and Conquer)

> 可以先想想如果要切出兩個矩形怎麼做
> 其實就是枚舉h或者w
> 如果要切出三個那就是做兩次
> 複雜度計算方式 可先思考一個function時間多久
> 一個function大約max(m,n)\*(mn)
> 但由於遞迴的話會再多一個m,n的loop
> 
> 注意切出的矩形要有一個1
> 

```c++
class Solution {
public:

    // get min rectangle that must contain at least one 1
    int getMinRectangle(vector<vector<int>>& grid, int si, int sj, int ei, int ej) {
        int li=ei, lj=ej, ri=si, rj=sj;
        bool one = false;
        for (int i = si; i <= ei; ++i) {
            for (int j = sj; j <= ej; ++j) {
                if (grid[i][j]) {
                    one = true;
                    li = min(li, i);
                    ri = max(ri, i);
                    lj = min(lj, j);
                    rj = max(rj, j);
                }
            }
        }
        return one ? (ri-li+1)*(rj-lj+1) : 1e9;
    }

    int splitRectangle(vector<vector<int>>& grid, int si, int sj, int ei, int ej, int split=2) {
        if (split == 0)
            return getMinRectangle(grid, si, sj, ei, ej);
        
        int ans = 1e9;
        // split horizational
        for (int h = si; h < ei; ++h) {
            ans = min(ans, splitRectangle(grid, si, sj, h, ej, 0) + splitRectangle(grid, h+1, sj, ei, ej, split-1));
            ans = min(ans, splitRectangle(grid, si, sj, h, ej, split-1) + splitRectangle(grid, h+1, sj, ei, ej, 0));
        }
        // split vetical
        for (int w = sj; w < ej; ++w) {
            ans = min(ans, splitRectangle(grid, si, sj, ei, w, 0) + splitRectangle(grid, si, w+1, ei, ej, split-1));
            ans = min(ans, splitRectangle(grid, si, sj, ei, w, split-1) + splitRectangle(grid, si, w+1, ei, ej, 0));
        }

        return ans;
    }

    int minimumSum(vector<vector<int>>& grid) {
        // goal: find the minimum sum that cover all 1 using exactly 3 rectangle
        // idea:
        // think 2 rectangle first
        // we can split vectical or horizatonal 
        // just do 2 times!
        
        int m = grid.size();
        int n = grid[0].size();
        return splitRectangle(grid, 0, 0, m-1, n-1);
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(mnmn) | O(1) |
