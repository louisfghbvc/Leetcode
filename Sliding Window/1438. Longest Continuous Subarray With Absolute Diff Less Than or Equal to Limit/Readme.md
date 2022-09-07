# [1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

###### tags: `leetcode` `medium` `deque` `sliding window`

[TOC]

## Description
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

## Way1 - deque

> as two pointers

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // goal: find the longest subarray such that the mx - mn <= limit
        // idea: maintain two deque
        // a max queue, a min queue
        // and two pointer
        
        int n = nums.size();
        deque<int> max_dq, min_dq; 
        int ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            // add r to queue
            while (max_dq.size() && nums[max_dq.back()] < nums[r])
                max_dq.pop_back();
            while (min_dq.size() && nums[min_dq.back()] > nums[r])
                min_dq.pop_back();
            max_dq.push_back(r);
            min_dq.push_back(r);
            
            // not good, move l
            while (nums[max_dq.front()] - nums[min_dq.front()] > limit) {
                if (max_dq.front() == l) max_dq.pop_front();
                if (min_dq.front() == l) min_dq.pop_front();
                l++;
            }
            
            ans = max(ans, r-l+1);
        }
        
        return ans;
    }
};
```

## Way2 - Multiset

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // goal: find the longest subarray such that the mx - mn <= limit
        // idea: sliding window
        
        int n = nums.size();
        multiset<int> st;
        int ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            st.insert(nums[r]);
            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[l++]));
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n) | O(n) |
| Way2 | O(nlogn) | O(n) |

