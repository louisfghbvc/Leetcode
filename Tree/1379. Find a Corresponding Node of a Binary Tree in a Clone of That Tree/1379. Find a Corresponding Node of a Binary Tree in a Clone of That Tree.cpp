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


// Morris traverse, space O(1)

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
