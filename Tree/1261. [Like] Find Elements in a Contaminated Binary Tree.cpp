// O(N) time O(N) space.
// O(1) query. easy dfs and use set.
class FindElements {
public:

    unordered_set<int> st;
    void dfs(TreeNode* root, int v = 0){
        if(!root) return;
        dfs(root->left, v*2+1);
        st.insert(v);
        dfs(root->right, v*2+2);
    }
    
    FindElements(TreeNode* root) {
        dfs(root);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};


// O(logN) time O(1) space. like trie. very fast.
// use target + 1.
//  1
//10 11 
// 0 left, 1 right. 
class FindElements {
public:
    
    TreeNode* mroot;
    FindElements(TreeNode* root) {
        mroot = root;
    }
    
    int len(int x){
        int cnt = 0;
        while(x){
            cnt++;
            x >>= 1;
        }
        return cnt;
    }
    
    bool find(int target) {
        target++;
        TreeNode* cur = mroot;
        
        int cnt = len(target);
        while(--cnt){
            bool b = target&(1<<(cnt-1));
            if(b && cur->right)
                cur = cur->right;
            else if(!b && cur->left)
                cur = cur->left;
            else return false;
        }
        
        return true;
    }
};
