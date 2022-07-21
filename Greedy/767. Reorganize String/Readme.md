# [767. Reorganize String](https://leetcode.com/problems/reorganize-string/)

###### tags: `leetcode` `medium` `greedy`

[TOC]

## Description
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

## Way1 - Groups

```c++
class Solution {
public:
    string reorganizeString(string s) {
        // goal: reorganize the string such that adjacent chars are not the same
        
        // idea: 
        // maximum frequencies must greater than others sum
        // simulate it -> divide to maximum groups
        
        // a_a_a_
        
        vector<int> fre(26);
        for (char c: s) fre[c-'a']++;
        
        int id = max_element(fre.begin(), fre.end()) - fre.begin();
        int sum = 0;
        for (int i = 0; i < 26; ++i) if (i != id) {
            sum += fre[i];
        }
        
        // impossible
        if (fre[id]-1 > sum) return "";
        
        vector<string> groups(fre[id], string(1, 'a'+id));
        fre[id] = 0;
        
        id = 0;
        for (int i = 0; i < 26; ++i) {
            while (fre[i]--) {
                groups[id] += 'a' + i;
                id++;
                if (id == groups.size()) id = 0;
            }
        }
        
        // flatten the group
        string res;
        for (auto &s: groups)
            res += s;
        return res;
    }
};
```

## Way2- Heap

> Note: only care top 2

```c++
class Solution {
public:
    string reorganizeString(string s) {
        // goal: reorganize the string such that adjacent chars are not the same
        
        // idea: 
        // maximum frequencies must greater than others sum
        // simulate it -> use max-heap
        // maintain previous pair
        
        vector<int> fre(26);
        for (char c: s) fre[c-'a']++;
        
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (fre[i]) 
                pq.push({fre[i], 'a'+i});
        }
        
        string res;
        pair<int, char> prev = {-1, '#'};
        while (pq.size()) {
            auto cur = pq.top(); pq.pop();
            res += cur.second;
            
            cur.first--;
            if (prev.first > 0) 
                pq.push(prev);
            prev = cur;
        }
        
        if (res.size() != s.size()) return "";
        return res;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n) | O(n) |
| Way2 | O(nlog26) | O(n) |

