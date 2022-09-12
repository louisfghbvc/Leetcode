# [862. Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)

###### tags: `leetcode` `hard` `greedy` `heap` `deque` `sliding window`

[TOC]

## Description
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

## Way1 - Heap

> key observation: once pair, we don't need to reserve in heap

```cpp
class Solution {
public:
    
    typedef pair<long, int> ii;
    
    int shortestSubarray(vector<int>& nums, int k) {
        // goal: find out shortest subarray such that sum at least k
        
        // idea: prefix sum
        // preR - preL >= k
        // preR - k >= preL, want R-L smallest
        
        // observe: preL >= preL1, L < L1
        // preL no use -> record smallest preL
        // when we find a valid pair, we should pop out smallest
        // since the smallest is used and the best (smallest length)
        
        int n = nums.size();
        
        int ans = 1e9;
        
        priority_queue<ii, vector<ii>, greater<>> pq;
        long sum = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum >= k) // base case
                ans = min(ans, i+1);
            
            while (pq.size() && sum - k >= pq.top().first) { // no use in pq
                ans = min(i - pq.top().second, ans);
                pq.pop();
            }
            
            pq.push({sum, i});
        }
        
        
        return ans == 1e9 ? -1 : ans;
    }
};
```

## Way2 - Deque + Greedy

> Same as above, but use deque to optimize
> Maintain smallest queue in front

```cpp
class Solution {
public:    
    int shortestSubarray(vector<int>& nums, int k) {
        // goal: find out shortest subarray such that sum at least k
        
        // idea: prefix sum
        // preR - preL >= k
        // preR - k >= preL, want R-L smallest
        
        // observe: preL >= preL1, L < L1
        // preL no use -> record smallest preL
        // when we find a valid pair, we should pop out smallest
        // since the pre is used and the best (smallest length), no need reserved
        
        // > optimized use min queue
        
        int n = nums.size();
        
        int ans = 1e9;
        
        vector<long> pre(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i)
            pre[i] += pre[i-1];
        
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            if (pre[i] >= k) ans = min(ans, i+1); // base case
            
            while (dq.size() && pre[i] - pre[dq.front()] >= k) { // front is best, no use in latter
                ans = min(ans, i - dq.front()); 
                dq.pop_front();
            }
            
            // maintain minimum
            while (dq.size() && pre[dq.back()] >= pre[i]) dq.pop_back();
            dq.push_back(i);
        }
        
        
        return ans == 1e9 ? -1 : ans;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(nlogn) | O(n) |
| Way2 | O(n) | O(n) |

