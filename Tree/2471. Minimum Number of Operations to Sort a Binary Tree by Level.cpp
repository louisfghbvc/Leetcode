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
    
    // minimum operations make arr sorted
    int cal(vector<int> &arr) {
        auto tmp = arr;
        sort(tmp.begin(), tmp.end()); // O(nlogn)
                
        unordered_map<int, int> idx; // value -> correct index
        for (int i = 0; i < arr.size(); ++i)
            idx[tmp[i]] = i;
        // 5->0, 6->1, ... 
        
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) { // O(n)
            if (arr[i] != tmp[i]) {
                int cycle = 1;
                while (arr[i] != tmp[i]) { 
                    swap(arr[i], arr[idx[arr[i]]]);
                    cycle++;
                }
                res += cycle-1;
            }    
        }
        return res;
    }
    
    int minimumOperations(TreeNode* root) {
        // goal: find the minimum operations of each level, need to be sorted order
        // idea: bfs
        // compute each level values
        
        queue<TreeNode*> q;
        q.push(root);
        
        int res = 0;
        while (q.size()) {
            vector<int> node;
            for (int qs = q.size(); qs; --qs) {
                TreeNode* cur = q.front(); q.pop();
                node.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res += cal(node);
        }
        return res;
    }
};
