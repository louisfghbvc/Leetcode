# [659. Split Array into Consecutive Subsequences](https://leetcode.com/problems/split-array-into-consecutive-subsequences/)

###### tags: `leetcode` `medium` `greedy` `hash table`

[TOC]

## Description
You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

## Way1 - Simulate use Heap

> No need only if min value+1 < current value

```cpp
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // goal: split into one or more subsequence such that 
        // each subsequence is increasing
        // idea: greedy, maintain a minheap
        // {val, length}
        // after that, insert into minheap
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // min-heap
        
        // [1,2,3,3,4,4,5,5]
        //              ^
        // pq: (4,3), (4,2)
        
        for (int x: nums) {
            while (pq.size() && pq.top().first+1 < x && pq.top().second > 2) // no need
                pq.pop();
            
            if (pq.empty() || pq.top().first+1 != x) {
                pq.push({x, 1});
            }
            else { // append it
                auto [a, len] = pq.top(); pq.pop();
                pq.push({x, len+1});
            }
        }
        
        // check valid
        while (pq.size()) {
            auto [x, len] = pq.top(); pq.pop();
            if (len < 3) return false;
        }
        
        return true;
    }
};
```

## Way2 - Dp + Greedy + Hash Table

> left[i]: remain count at i
> end[i]: number of count ending at i

```cpp
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // goal: split into one or more subsequence such that 
        // each subsequence is increasing
        // idea: greedy, use hashtable
        // if we have x-1
        // greedy append it in i, 
        // otherwise, try to see future if have x+1, x+2
        // try do in future
        
        unordered_map<int, int> left, end;
        
        for (int x: nums)
            left[x]++;
        
        for (int x: nums) {
            if (left[x] == 0) continue; // no x
            left[x]--;
            if (end[x-1] > 0) {
                end[x-1]--;
                end[x]++;
            }
            else if (left[x+1] && left[x+2]) {
                left[x+1]--;
                left[x+2]--;
                end[x+2]++;
            }
            else return false;
        }
        
        return true;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(nlogn) | O(n) |
| Way2 | O(n) | O(n) |

