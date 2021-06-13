// Stack to postfix Dp. Useful. O(N)

class Solution {
public:
    
    struct node{
        char val;
        node* left;
        node* right;
        node(char val) : val(val){}
        node(char v, node* l, node *r){
            val = v;
            left = l;
            right = r;            
        }
    };
    
    node* expTree(string &s){
        stack<node* > st;
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            node *root = new node(c);
            if(!isdigit(c)){
                root->right = st.top(); st.pop();
                root->left = st.top(); st.pop();                
            }
            st.push(root);
        }
        return st.top();
    }
    
    array<int, 2> dfs(node* root){ // turn 0 cost, turn 1 cost
        if(!root) return {0, 0};
        if(root->val == '1') return {1, 0};
        if(root->val == '0') return {0, 1};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        int zero, one;
        if(root->val == '|'){
            // 0|0, 0&1, 1&0
            zero = min({left[0] + right[0], 1 + left[0] + right[1], 1 + left[1] + right[0]});
            // 0|1, 1|0, 1|1, no need: 1&1
            one = min({left[0] + right[1], left[1] + right[0], left[1] + right[1]});
        }
        else{
            // 0&1, 1&0, 0&0
            zero = min({left[0] + right[1], left[1] + right[0], left[0] + right[0]});
            // 1&1, 0|1, 1|0
            one = min({left[1] + right[1], 1 + left[0] + right[1], 1 + left[1] + right[0]});
        }
        return {zero, one};
    }
    
    string ConvertPostFix(string &s){
        stack<char> st; // opertion stack
        map<char, int> mp = {{'|', 0}, {'&', 0}, {'(', -1}}; // priority
        
        string tmp = ""; // convert infix to postfix
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            if(isdigit(c)){
                tmp += c;
            }
            else{
                if(c == '(') st.push(c);
                else{
                    if(c == ')'){
                        while(st.size() && st.top() != '('){
                            tmp += st.top(); st.pop();
                        }
                        if(st.size()) st.pop(); // pop '('
                    }
                    else{
                        while(st.size() && mp[c] <= mp[st.top()]){  // need pop, cuz stack is prior
                            tmp += st.top(); st.pop();
                        }
                        st.push(c);
                    }
                }
            }
        }

        while(st.size()){
            tmp += st.top(); st.pop();
        }
        return tmp;
    }
    
    int minOperationsToFlip(string expression) {
        string s = ConvertPostFix(expression);
        node* root = expTree(s);
        auto res = dfs(root);
        return abs(res[0] - res[1]);
    }
};
