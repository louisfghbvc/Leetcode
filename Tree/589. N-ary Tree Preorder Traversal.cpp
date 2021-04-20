// O(N). Preorder

class Solution {
public:
    vector<int> res;
    void dfs(Node* root){
        if(!root) return;
        res.push_back(root->val);
        for(auto &child: root->children)
            dfs(child);
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return res;
    }
};

// O(N). Iterative


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        
        stack<Node*> st;
        st.push(root);
        while(st.size()){
            Node* cur = st.top(); st.pop();
            res.push_back(cur->val);
            
            for(int i = cur->children.size() - 1; i >= 0; --i){
                st.push(cur->children[i]);
            }
            
        }
        return res;
    }
};
