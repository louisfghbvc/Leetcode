// O(N). Simple stack
class Solution {
public:
    // when we encounter the operators. just pop two stack values
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> st;
        for(auto &s: tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if(s == "+"){
                    st.push(a+b);
                }
                if(s == "-"){
                    st.push(a-b);
                }
                if(s == "*"){
                    st.push(a*b);
                }
                if(s == "/"){
                    st.push(a/b);
                }
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};
