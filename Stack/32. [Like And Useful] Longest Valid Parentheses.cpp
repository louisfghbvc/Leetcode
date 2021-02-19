// O(N). use index stack, check most continuous length.
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        
        stack<int> st;
        st.push(-1);
        
        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                st.push(i);
            }    
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }    
                else{
                    res = max(res, i - st.top());
                }
            }
        }
        
        return res;
    }
};

// O(N) index stack, more intuitive.
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        
        stack<int> st;
        
        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                st.push(i);
            }    
            else{
                if(st.empty() || s[st.top()] != '('){
                    st.push(i);
                }    
                else{
                    st.pop();
                }
            }
        }
        
        if(st.empty()) res = n;
        else{
            int r = n;
            while(st.size()){
                res = max(res, r - st.top() - 1);
                r = st.top();
                st.pop();
            }
            // last to begin.
            res = max(res, r);
        }
        return res;
    }
};
