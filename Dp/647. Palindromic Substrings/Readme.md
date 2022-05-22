# [647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)

###### tags: `leetcode` `medium` `two pointers` `manacher`

[TOC]

## Description
Calculate the substring that is palindrome.

## Way1 - Two pointers
```cpp=
class Solution {
public:
    int countSubstrings(string s) {
        // goal: count the substring that is palindrome
        // idea: for each index, extend the left, right position
        // say if maximum length of the string is (aaa) -> have 2 palindrome
        
        int n = s.size();
        auto cal = [&](int l, int r) -> int {
            int ori_l = l, ori_r = r;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            } 
            return ori_l - l;
        };
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            // do odd, even palindrome
            res += cal(i, i);
            res += cal(i, i+1);
        }
        
        return res;
    }
};
```

## Way2 - Manacher
```c++
class Solution {
public:
    
    int countSubstrings(string s) {
        // goal: count the substring that is palindrome
        // idea: manacher
        
        int n = s.size();
        int ans = 0;
        
        vector<int> d1(n); // odd
        vector<int> d2(n); // even
        // d1[i]: length of palindrome from index i of half 
        // d2[i]: length of palindrome from index i and i-1
        
        for(int i = 0, l = 0, r = -1; i < n; ++i){
            int k = i > r ? 1 : min(d1[l + r - i], r - i + 1); // why l+r-i ?, since this is right bound from right is same as left bound from left 
            while(i - k >= 0 && i + k < n && s[i + k] == s[i - k]) k++;
            d1[i] = k--;
            if(i + k > r){
                l = i - k;
                r = i + k;
            }
            ans += d1[i];
        }
        
        for(int i = 0, l = 0, r = -1; i < n; ++i){
            int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1); // !!! l-r+i+1, must add 1
            while(i - k - 1 >= 0 && i + k < n && s[i - 1 - k] == s[i + k]) k++;
            d2[i] = k--;
            if(i + k > r){
                l = i - 1 - k;
                r = i + k;
            }
            ans += d2[i];
        }
        
        return ans;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n^2) | O(1) |
| Way2 | O(n) | O(n) |
