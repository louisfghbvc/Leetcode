# [60. Permutation Sequence](https://leetcode.com/problems/permutation-sequence/)

###### tags: `leetcode` `hard` `math`

[TOC]

## Description
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.


## Way1 - Brute Force

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        // goal: get the kth permutation
        // idea: brute force
            
        string tmp(n, '0');
        for (int i = 0; i < n; ++i)
            tmp[i] = '0'+i+1;
        
        k--; // 0-based
        
        do {
            if (k == 0) return tmp;
            k--;
        } while (next_permutation(tmp.begin(), tmp.end()));
        
        return tmp;
    }
};
```

## Way2 - Math + Comb

> 每個位置找到是誰開頭，直接除以階乘就能找到了

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        // goal: get the kth permutation
        // idea: count from left to right
        // each bit find correct number
        
        vector fac(n+1, 1);
        for (int i = 1; i <= n; ++i)
            fac[i] = i*fac[i-1];
        
        k--;
        
        string digits;
        for (int i = 1; i <= n; ++i)
            digits += '0'+i;
        
        string res;
        
        // 1xx - 2!  k in [0~1]
        // 2xx - 2!  k in [2~3]
        // 3xx - 2!  k in [4~5]
        
        for (int i = 0; i < n; ++i) {
            int num = k / fac[n-i-1];
            res += digits[num];
            digits.erase(digits.begin() + num);   
            k %= fac[n-i-1];
        }
        
        return res;
    }
};


```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n\*n!) | O(n) |
| Way2 | O(n^2) | O(n) |
