// Use Recursive skill always make things simple
// if root == key, can into 4 case.
// root has only 1 child, return the other child. (left return right, same as right) means current node is delete.
// so if has two child, we need to find the successor of tree.
// so rightmin, or leftmax. here is rightmin.
// after find rightmin, assign value(not a good idea, but for newbie I think easier to understand)
// so the target change. now delete right tree. rightT = (rightTree, new target)
// The recursive tech. is very useful to solve something like difficult to think problem.
// just do one level by level. recursive main idea is push work to other. and make it so clean.

// O(h).

class Solution {
public:
    TreeNode* FindMin(TreeNode* root){
        while(root->left) root = root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            // no need to check both NULL
            if(!root->left) return root->right;
            else if(!root->right) return root->left;
            
            // have both child, find minimum in right and assign, rebuild.
            TreeNode* minRight = FindMin(root->right);
            root->val = minRight->val;
            root->right = deleteNode(root->right, minRight->val);
        }
        return root;
    }
};
