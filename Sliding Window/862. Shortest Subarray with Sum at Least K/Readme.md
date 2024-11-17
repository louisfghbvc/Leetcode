# [862. Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)

###### tags: `leetcode` `hard` `greedy` `heap` `deque` `sliding window`

[TOC]

## Description
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

## Way1 - Heap

> key observation: once pair, we don't need to reserve in heap
> each pre[l-1] use at most once...

```cpp
class Solution {
public:
    struct BIT {
        int N;
        vector<int> arr;
        BIT (int n) : N(n+1), arr(n+1, -2) {}
        void add(int x, int v) {
            for (++x; x < N; x+=x&-x)
                arr[x] = max(arr[x], v);
        }
        int sum(int x) {
            int res = -2; // init
            for (++x; x; x-=x&-x)
                res = max(res, arr[x]);
            return res;
        }
    };

    int shortestSubarray(vector<int>& nums, int k) {
        // goal: find the shortest subarray sum >= k

        // idea:
        // binary search the length?
        // for each length easily using two pointers

        // wrong, num has neg
        // can we shift the value to positive? wrong

        // think prefix sum
        // pre[r] - pre[l-1] >= k
        // pre[r] - k >= pre[l-1]

        // [1, 2, 1]
        // 1 1 -1
        // why not we just use BIT?
        // we can find the maximum index smaller than pre[r]-k

        // idea2:
        // using heap, since we need to find smallest!!
        // means each pre[l-1] only use at most once!!!!!!!!!
        // when pre[r] - pre[l-1] >= k, pop out pre[l-1]

        using T = pair<long, long>;
        priority_queue<T, vector<T>, greater<>> pq; // {val, index}
        pq.emplace(0, -1);

        int n = nums.size();
        int ans = n+5;
        long pre = 0;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            while (pq.size() && pre - pq.top().first >= k) {
                ans = min<int>(ans, i - pq.top().second);
                pq.pop();
            }
            pq.emplace(pre, i);
        }
        return ans == n+5 ? -1 : ans;
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

