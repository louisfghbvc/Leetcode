/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

// Recursive. Inorder traversal. O(N)
class Solution {
public:
    Node* pre = NULL, *first = NULL;
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        
        // going left
        treeToDoublyList(root->left);
        
        // set head
        if(!first) first = root;
        
        if(pre) pre->right = root;
        root->left = pre;
        
        pre = root;
        
        // going right
        treeToDoublyList(root->right);
        
        first->left = pre;
        pre->right = first;
        
        return first;
    }
};
