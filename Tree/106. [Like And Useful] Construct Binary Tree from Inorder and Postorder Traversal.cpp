// O(N). use map to record the index of inorder value.
// so the key point is find the mid, mid is postorder end.
class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* helper(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr){
        if(il >= ir || pl >= pr) return NULL;
        
        int mid = postorder[pr-1];
        int dis = mp[mid] - il;
        
        TreeNode* root = new TreeNode(mid);
        root->left = helper(inorder, il, il + dis, postorder, pl, pl + dis);
        root->right = helper(inorder, il + dis + 1, ir, postorder, pl + dis, pr - 1);
            
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
        return helper(inorder, 0, inorder.size(), postorder, 0, inorder.size());
    }
};

// O(NlogN). no use map
class Solution {
public:
    TreeNode* helper(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr){
        if(il >= ir || pl >= pr) return NULL;
        
        int mid = postorder[pr-1];
        auto f = find(inorder.begin()+il, inorder.begin()+ir, mid);
        int dis = f - (inorder.begin()+il);
        
        TreeNode* root = new TreeNode(mid);
        root->left = helper(inorder, il, il + dis, postorder, pl, pl + dis);
        root->right = helper(inorder, il + dis + 1, ir, postorder, pl + dis, pr - 1);
            
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size(), postorder, 0, inorder.size());
    }
};
