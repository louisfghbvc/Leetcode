# [2322. Minimum Score After Removals on a Tree](https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/)

###### tags: `leetcode` `hard` `tree` `dp`

[TOC]

## Description
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Remove two distinct edges of the tree to form three connected components. For a pair of removed edges, the following steps are defined:

Get the XOR of all the values of the nodes for each of the three components respectively.
The difference between the largest XOR value and the smallest XOR value is the score of the pair.
For example, say the three components have the node values: [4,5,7], [1,9], and [3,3,3]. The three XOR values are 4 ^ 5 ^ 7 = 6, 1 ^ 9 = 8, and 3 ^ 3 ^ 3 = 3. The largest XOR value is 8 and the smallest XOR value is 3. The score is then 8 - 3 = 5.
Return the minimum score of any possible pair of edge removals on the given tree.



## Way1 - Tree + Enumerate + Dp

```cpp
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        // goal: minimum the XOR score different
        // idea: given a root tree, enumerate two node
        // get the score
        // step1, compute each node subtree xor value
        // step2, use a timestamp to determine the two node is in same subtree
        
        int n = nums.size();
        
        vector<vector<int>> tree(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        
        vector subtreeXOR(n, 0);
        vector in(n, 0), out(n, 0); // in out stamp
        int stamp = 0;
        
        auto dfs = [&](const auto &self, int u, int p) -> int {
            in[u] = ++stamp;
            int res = nums[u];
            for (int v: tree[u]) {
                if (v != p) {
                    res = res ^ self(self, v, u);
                }
            }
            out[u] = ++stamp;
            return subtreeXOR[u] = res;
        };
        
        dfs(dfs, 0, -1);
        
        // if x is y parent return true
        auto isParent = [&](int x, int y) {
            return in[x] <= in[y] && out[x] >= out[y];
        };
        
        // enumerate the two nodes
        int score = INT_MAX;
        for (int i = 1; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int a = subtreeXOR[0];
                int b = subtreeXOR[i], c = subtreeXOR[j];
                if (isParent(i, j)) {
                    b ^= c;
                }
                else if (isParent(j, i)) {
                    c ^= b;
                }
                a = a^b^c;
                score = min(score, max({a, b, c}) - min({a, b, c}));
            }
        }
        
        return score;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n^2) | O(n) |
