# [2597. The Number of Beautiful Subsets](https://leetcode.com/problems/the-number-of-beautiful-subsets/)

###### tags: `leetcode` `medium` `dp` `backtracking`

[TOC]

## Description
Check that if we can reach the last index

## Way1 - Dp

```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        // goal: find the subset that is not distance k
        // idea: house robber
        // each mod divide into same group
        // seperate by group
        // each group calculate the ans
        // duplicate num -> do all in once

        unordered_map<int, int> fre;
        unordered_map<int, vector<int>> groups;
        for (int x: nums) {
            if (!fre.count(x))
                groups[x%k].push_back(x);
            fre[x]++;
        }

        int ans = 1;
        for (auto &[_, g]: groups) {
            sort(g.begin(), g.end());

            int prev = -1;
            // each x, we can choose or skip
            int no_choose = 1, choose = 0;
            for (int x: g) {
                int num = pow(2, fre[x]) - 1; // nums of way, no empty contain x
                if (prev + k == x) {
                    int x_no_choose = no_choose + choose;
                    int x_choose = no_choose * num;
                    no_choose = x_no_choose;
                    choose = x_choose;
                }
                else {
                    int x_no_choose = no_choose + choose;
                    int x_choose = (no_choose + choose) * num;
                    no_choose = x_no_choose;
                    choose = x_choose;
                }
                prev = x;
            }

            ans *= no_choose + choose; // disinct, so that we product all possible
        }

        return ans - 1; // minus empty case
    }
};
```

## Way2 - iterative backtracking

```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        // goal: find the beatutiful subsets
        // idea: 
        // backtracking all subset
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int ans = 0;
        vector<int> st(2005);
        for (int mask = 1; mask < (1<<n); ++mask) {
            bool good = true;
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) {
                    if (st[nums[i]+1000 - k] == mask) {
                        good = false;
                        break;
                    }
                    else st[nums[i]+1000] = mask;
                }
            }
            ans += good;
        }
        
        return ans;
    }
};
```

## Way3 - Backtracking + Prune

```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        // goal: find the beatutiful subsets
        // idea: 
        // backtracking all subset
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int ans = 0;
        
        vector<int> arr;
        vector<int> vis(2005);
        
        auto dfs = [&](auto &self, int i) -> void {
            if (i == n) {
                ans += !arr.empty();
                return;
            }    
            
            // skip
            self(self, i+1);
            
            // used
            arr.push_back(nums[i]);
            vis[nums[i]+1000]++;
            if (vis[nums[i]+1000-k] == 0) {
                self(self, i+1);
            }
            vis[nums[i]+1000]--;
            arr.pop_back();
        };
        dfs(dfs, 0);
        
        return ans;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(nlogn + k) | O(k) |
| Way1 | O(n2^n) | O(k) |
| Way1 | O(2^n) | O(k) |

