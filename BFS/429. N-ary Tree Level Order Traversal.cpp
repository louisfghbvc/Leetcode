/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// O(N). Just BFS.
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            vector<int> cur;
            for(int qs = q.size()-1; qs >= 0; --qs){
                Node* tmp =  q.front(); q.pop();
                cur.push_back(tmp->val);
                for(Node *child: tmp->children){
                    q.push(child);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};
