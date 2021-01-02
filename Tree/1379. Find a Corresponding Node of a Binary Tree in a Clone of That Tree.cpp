// O(N) and also have follow up.

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        if(original == target) return cloned;
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if(left) return left;
        TreeNode* right = getTargetCopy(original->right, cloned->right, target);
        return right;
    }
};
