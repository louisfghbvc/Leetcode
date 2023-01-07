# [134. Gas Station](https://leetcode.com/problems/gas-station/description/)

###### tags: `leetcode` `medium` `greedy`

[TOC]

## Description


## Way1 - Next Position

> proof by contraction

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // goal: find we can go through all gas tank
        // idea:
        // impossible ? sum of gas[i]-cost[i] < 0
        // start from index 0 to i
        // if < 0
        // 0...i can ignore since if j..i can reach, but 0..j also can reach
        // contraction

        int n = gas.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += gas[i] = gas[i]-cost[i];
        if (sum < 0) return -1;

        int pos = 0;
        int val = 0;
        for (int i = 0; i < n; ++i) {
            val += gas[i];
            if (val < 0) pos = i+1, val = 0;
        }
        return pos;
    }
};
```

## Way2 - Suffix Maximum

```
 consider
 +,+,+,-,+,+,+,-
         mx
         [+,+,+,-] <- suffix sum 
```
```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum = accumulate(gas.begin(), gas.end(), 0);
        int cost_sum = accumulate(cost.begin(), cost.end(), 0);
        
        // impossible
        if(cost_sum > gas_sum) return -1;
        
        int max_i = -1, max_value = -1;
        int diff = 0;
        for(int i = gas.size()-1; i >= 0; --i){
            diff += gas[i] - cost[i];
            if(diff > max_value){
                max_value = diff;
                max_i = i;
            }
        }
        
        return max_i;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n) | O(1) |
| Way2 | O(n) | O(1) |

