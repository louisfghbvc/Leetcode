# [1338. Reduce Array Size to The Half](https://leetcode.com/problems/reduce-array-size-to-the-half/)

###### tags: `leetcode` `medium` `greedy`

[TOC]

## Description


## Way1 - Greedy + Sort

```cpp
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // goal: remove the min set
        // such that all occurrence remove at least half
        // idea: greedy
        // count the frequency, and choose the maximum until greater then size/2
        
        int n = arr.size();
        
        unordered_map<int, int> fre;
        for (int x: arr)
            fre[x]++;
        
        vector<int> fre_arr;
        for (auto &[a, f]: fre)
            fre_arr.push_back(f);
        
        sort(fre_arr.begin(), fre_arr.end(), greater<>());
        
        
        int sum = 0;
        int i = 0;
        while (sum < n/2) {
            sum += fre_arr[i];
            i++;
        }
        
        return i;
    }
};
```

## Way2 - Greedy + Bucket sort

```cpp
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // goal: remove the min set
        // such that all occurrence remove at least half
        // idea: greedy
        // count the frequency, and choose the maximum until greater then size/2
        
        int n = arr.size();
        
        unordered_map<int, int> fre;
        for (int x: arr)
            fre[x]++;
        
        vector<int> bucket(n+1);
        for (auto &[a, f]: fre)
            bucket[f]++;
        
        
        int sum = 0;
        int used = 0;
        int idx = n;
        while (sum < n/2) {
            while (bucket[idx] == 0) idx--;
            sum += idx;
            used++;
            bucket[idx]--;
        }
        
        return used;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(nlogn) | O(n) |
| Way2 | O(n) | O(n) |

