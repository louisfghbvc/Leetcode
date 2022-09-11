# [2398. Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget/)

###### tags: `leetcode` `hard` `sliding window`

[TOC]

## Description
You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, both of length n. The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] units to run. You are also given an integer budget.

The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts), where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is the sum of running costs among the k robots.

Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.

## Way1 - Deque + Slding window


```cpp
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        // goal: find the maximum robots that cost <= buget
        // idea: sliding window, maintain max charge time
        
        int n = chargeTimes.size();
        
        deque<int> dq; // decreasing chargeTimes index
        
        int ans = 0;
        long sum = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            // push into deque
            while (dq.size() && chargeTimes[dq.back()] < chargeTimes[r]) dq.pop_back();
            dq.push_back(r);
        
            sum += runningCosts[r];
            
            while (dq.size() && chargeTimes[dq.front()] + sum*(r-l+1) > budget) {
                if (dq.front() == l) dq.pop_front();
                sum -= runningCosts[l];
                l++;
            }
            
            ans = max(ans, r-l+1);
        }
        
        return ans;
    }
};
```

## Way2 - Binary Search Ans + Deque

```cpp
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        // goal: find the maximum consecutive robots, such that cost <= budget
        // max(chargeTimes) + k * sum(runningCosts) <= budget
        // idea: binary search k
        // each k, sliding window the cost value
        
        int n = runningCosts.size();
        
        
        // true, if can choose window size k. cost <= budget
        // O(n)
        auto check = [&](int k) {
            if (k == 0) return true;
            
            deque<int> dq; // monotonic decreasing queue
            long sum = 0;
            for (int i = 0; i < k; ++i) {
                while (dq.size() && chargeTimes[dq.back()] <= chargeTimes[i]) dq.pop_back(); 
                dq.push_back(i);
                sum += runningCosts[i];
            }
            
            if (chargeTimes[dq.front()] + sum*k <= budget) return true;
            for (int i = k; i < n; ++i) {
                while (dq.size() && i - dq.front() >= k) dq.pop_front();
                while (dq.size() && chargeTimes[dq.back()] <= chargeTimes[i]) dq.pop_back(); 
                dq.push_back(i);
                sum += runningCosts[i];
                sum -= runningCosts[i-k];
                if (chargeTimes[dq.front()] + sum*k <= budget) return true;
            }
            
            return false;
        };
        
        int ans = 0;
        int l = 0, r = n;
        
        while (l <= r) {
            int mid = (l+r)/2;
            if (check(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }
        
        return ans;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n) | O(n) |
| Way1 | O(nlogn) | O(n) |

