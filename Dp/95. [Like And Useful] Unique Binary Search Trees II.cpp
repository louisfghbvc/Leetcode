// choose i, and we can split into two gen(l, i-1), gen(i+1, r) and Enum all case, then merge.
// and base is l > r add NULL and return.
// Very trick 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> gen(int l, int r){
        vector<TreeNode*> res;
        if(l > r){
            res.push_back(0);
            return res;
        }
        
        for(int i = l; i <= r; ++i){
            vector<TreeNode*> leftTree = gen(l , i-1);
            vector<TreeNode*> rightTree = gen(i+1 , r);
            
            for(auto left: leftTree){
                for(auto right: rightTree){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }  
        }
        
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return gen(1, n);
    }
};
