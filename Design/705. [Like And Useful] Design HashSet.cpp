// Well... can use array or set.
// here implement BST. it's good to pratice Recursive.
// use TreeNode. the idea is really simple. a bst is easy to learn. very cool.
// each operator is O(logN).

class MyHashSet {
private:
    TreeNode *root;   
    
    TreeNode* FindSuccessor(TreeNode* root){
        while(root->left) root = root->left;
        return root;
    }
    
    TreeNode* Find(TreeNode* root, int target){
        if(!root) return NULL;
        if(root->val == target) return root;
        else if(root->val > target) return Find(root->left, target);
        return Find(root->right, target);
    }
    
    TreeNode* InsertNode(TreeNode* root, int key){
        if(!root){
            root = new TreeNode(key);
        }
        else{
            if(root->val > key){
                root->left = InsertNode(root->left, key);
            }
            else if(root->val < key){
                root->right = InsertNode(root->right, key);
            }
        }
        return root;
    }
    
    TreeNode* DeleteNode(TreeNode* root, int key){
        if(!root) return NULL;
        if(root->val > key){
            root->left = DeleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = DeleteNode(root->right, key);
        }
        else{
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            TreeNode* suc = FindSuccessor(root->right);
            root->val = suc->val;
            root->right = DeleteNode(root->right, suc->val);
        }
        return root;
    }
    
public: 
    MyHashSet() {
        root = NULL;
    }
    
    void add(int key) {
        root = InsertNode(root, key);
    }
    
    void remove(int key) {
        root = DeleteNode(root, key);
    }
    
    bool contains(int key) {
        if(Find(root, key) != NULL) return true;
        return false;
    }
};
