# [995. Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/)

###### tags: `leetcode` `hard` `line sweep`

[TOC]

## Description


## Way1 - Diff Array
> change the future update
```c++
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // goal: find the minimum flips that can make nums to all 1
        // idea: line sweep, for each position
        // try to see the prefix difference accumulate
        // if current is 0, prefix is even -> flip
        // if current is 1, prefix is odd -> flip
        
        vector<int> upd(nums.size()+1); // upd[i]: record change about ind i
        
        int pre = 0;
        int ops = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pre += upd[i];
            if ((pre + nums[i]) % 2 == 0) { // should change
                ops++;
                pre++;
                upd[i]++;
                if (i + k > nums.size()) return -1; // too much
                upd[i+k]--;
            }
        }
        
        return ops;
    }
};
```

## Way2 - Sliding Window + Diff 
> change the future is difficult, so change the past XDD
> if nums[i - k] is changed means that prefix update difference should subtract 1 (think the sliding window!!)

```c++
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // goal: find the minimum flips that can make nums to all 1
        // idea: line sweep, for each position
        // try to see the prefix difference accumulate
        // if current is 0, prefix is even -> flip
        // if current is 1, prefix is odd -> flip
        
        // state 2: nums[i] is flipped
        
        int pre = 0;
        int ops = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - k >= 0 && nums[i - k] == 2)
                pre--;
            if ((nums[i] + pre) % 2 == 0) {
                if (i + k > nums.size()) return -1;
                pre++;
                ops++;
                nums[i] = 2; // flip!
            }
        }
        
        return ops;
    }
};
```


## Complexity

| complexity | time | space |
| - | - | - |
| Way1 - Diff Array| O(n) | O(n) |
| Way2 - In place | O(n) | O(1) |
