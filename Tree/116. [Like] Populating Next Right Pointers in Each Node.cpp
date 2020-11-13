// O(1) space. O(N). level-by-level

class Solution {
public:
    Node* connect(Node* root) {
        Node* tmp = root;
        while(tmp && tmp->left){
            Node* cur = tmp;
            while(cur){
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : NULL;
                cur = cur->next;
            }
            tmp = tmp->left;
        }
        return root;
    }
};

// Simple O(N) space.
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            Node* prev = NULL;
            for(int s = q.size()-1; s >= 0; --s){
                Node* cur = q.front(); q.pop();
                if(prev != NULL) prev->next = cur; 
                prev = cur;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};
