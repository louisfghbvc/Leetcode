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
        if(!root) return "#";
        string left = serialize(root->left);
        string right = serialize(root->right);
        // hash
        string sign = root->val > 0 ? "+" : "";
        return sign + to_string(root->val) + "." + left + "." + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int i = 0;
        function<TreeNode*()> dfs = [&]() -> TreeNode* {
            if(i == data.size()) return NULL;
            if(data[i] == '#'){
                i++;
                return NULL;
            }
            
            int val = 0;
            bool sign = data[i++] == '+' ? 1 : 0;
            while(data[i] != '.'){
                val = val * 10 + data[i] - '0';
                i++;
            }
            if(!sign) val = -val;
            
            TreeNode* root = new TreeNode(val);
            i++; // ignore .
            root->left = dfs();
            i++; // ignore .
            root->right = dfs();
            return root;
        };
        
        return dfs();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
