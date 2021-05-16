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


// Concise dp O(N).
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
    
    // return: no_cam, current covered no_cam, put_cam
    vector<int> dfs(TreeNode* root){
        if(!root) return {0, 0, 99999};
        
        auto L = dfs(root->left);
        auto R = dfs(root->right);
        
        int p0 = L[1] + R[1]; // subtree covered.
        int p1 = min(R[2] + min(L[1], L[2]), L[2] + min(R[1], R[2])); // from left or right cam
        int p2 = 1 + min({L[0], L[1], L[2]}) + min({R[0], R[1], R[2]}); // cur put cam
        return {p0, p1, p2};
    }
    
    int minCameraCover(TreeNode* root) {
        auto res = dfs(root);
        return min(res[1], res[2]);
    }
};
