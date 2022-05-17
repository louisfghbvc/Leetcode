# [1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)

###### tags: `leetcode` `medium` `dfs`

[TOC]

## Description
Find the target node that is in the orginal tree, and return the same position of target node in the cloned tree.

## Way1
dfs, just moving the both tree
```cpp
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // goal: find the target node that is in the cloned tree
        // idea: do inorder traversal
        if (!original) return nullptr;
        if (original == target) return cloned;
        
        auto left = getTargetCopy(original->left, cloned->left, target);
        if (left) return left;
        
        auto right = getTargetCopy(original->right, cloned->right, target);
        return right;
    }
};
```

## Way2 - Morris Traverse
> 注意不能修改tree的結構, 記得還原
```cpp
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // goal: find the target node that is in the cloned tree
        // idea: morris traverse
        
        TreeNode* cur = original, *cur_cloned = cloned;
        TreeNode* ret = nullptr;
        
        while (cur) {
            if (cur->left) { // find predecessor (closest node in left subtree)
                TreeNode* tmp = cur->left;
                TreeNode* tmp_cloned = cur_cloned->left;
                
                while (tmp->right && tmp->right != cur) {
                    tmp = tmp->right;
                    tmp_cloned = tmp_cloned->right;
                }
                
                if (tmp->right) { // already connect to root, left tree all finished
                    tmp->right = nullptr;   
                    tmp_cloned->right = nullptr;
                    if (cur == target) ret = cur_cloned;
                    cur = cur->right;
                    cur_cloned = cur_cloned->right;
                }
                else {
                    tmp->right = cur;
                    tmp_cloned->right = cur_cloned;
                    cur = cur->left;
                    cur_cloned = cur_cloned->left;
                }
            }
            else { // no left, so current node is done
                if (cur == target) ret = cur_cloned; 
                cur = cur->right;
                cur_cloned = cur_cloned->right;
            }
        }
        
        return ret;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(n) | O(n) |
| Way2 | O(n) | O(1) |
