// BFS build string, and just use the origin order insert Node to BST. simple.
// O(NlogN).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res = "";
        while(q.size()){
            for(int s = q.size()-1; s >= 0; s--){
                TreeNode* cur = q.front(); q.pop();
                if(!cur) continue;
                res += to_string(cur->val) + " ";
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return res;
    }
    
    TreeNode* insertNode(TreeNode* root, int val){
        if(!root) return new TreeNode(val);
        if(root->val > val) root->left = insertNode(root->left, val);
        else root->right = insertNode(root->right, val);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int tmp = 0;
        TreeNode* root = NULL;
        for(char c: data){
            if(c == ' '){
                root = insertNode(root, tmp);
                tmp = 0;
            }
            else tmp = tmp*10 + (c-'0');
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
