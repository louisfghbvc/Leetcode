/*
// Simple BFS. see the problem example, and observe that the next is just the same level.
// O(N). Space O(N).

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            Node* pre = NULL;
            for(int s = q.size()-1; s >= 0; --s){
                Node* cur = q.front(); q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                if(!pre) pre = cur;
                else pre->next = cur, pre = cur;
            }
        }
        return root;
    }
};
