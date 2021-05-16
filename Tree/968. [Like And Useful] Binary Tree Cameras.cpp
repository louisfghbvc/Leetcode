// Postorder Greedy. 3 state. from top is hard to think.
// because u don't know how to do in the first time.
// so if a child no_cam, then must add.
// or if a child has_cam, then no need.
// otherwise no_cam. u don't need to put cam this time. cuz father can do.
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
    #define NO_NEED 1
    #define HAS_CAM 2
    #define NO_CAM 3
    
    int res = 0;
    int dfs(TreeNode* root){
        if(!root) return NO_NEED;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(l == NO_CAM || r == NO_CAM){
            res++;
            return HAS_CAM;
        }
        if(l == HAS_CAM || r == HAS_CAM)
            return NO_NEED;
        return NO_CAM;
    }   
    
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == NO_CAM) res++;
        return res;
    }
};
