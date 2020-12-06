
// Simple BFS. see the problem example, and observe that the next is just the same level.
// O(N). Space O(N).

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

// O(N). O(1) Space. use next pointer to know bfs.

class Solution {
public:
    Node* connect(Node* root) {
        Node* res = root;
        Node* leftmost = new Node(0);
        while(root){
            Node* cur = leftmost;
            cur->next = NULL;
            while(root){
                if(root->left){
                    cur->next = root->left;
                    cur = cur->next;
                }
                if(root->right){
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = leftmost->next;
        }
        return res;
    }
};
