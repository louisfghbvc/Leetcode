# [528. Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)

###### tags: `leetcode` `medium` `random` `prefix`

[TOC]

## Description
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).


## Way1 - Bianry search + prefix sum

```cpp=
class Solution {
public:
    
    vector<int> pre;
    
    Solution(vector<int>& w) {
        pre = w;
        partial_sum(w.begin(), w.end(), pre.begin());
    }
    
    // goal: pick index base on probability
    // 1, 4, rand in this range
    // idea: build prefix sum
    // binary search the value in which index
    int pickIndex() {
        int x = rand() % pre.back() + 1;
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(logn) | O(n) |
