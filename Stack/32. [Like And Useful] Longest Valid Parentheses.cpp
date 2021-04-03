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


// Dp. check ')'. two case.

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n);
        
        int mx = 0;
        for(int i = 1; i < n; ++i){
            if(s[i] == ')'){
                if(s[i-1] == '(') dp[i] = (i-2 < 0 ? 0 : dp[i-2]) + 2;
                else{ // i-1 = ')'
                    if(i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '('){ 
                        int prev = i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0;
                        dp[i] = dp[i-1] + prev + 2;
                    } 
                }
            }
            mx = max(mx, dp[i]);
        }
        
        return mx;
    }
};
