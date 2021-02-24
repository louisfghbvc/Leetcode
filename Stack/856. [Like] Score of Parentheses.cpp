// O(N).
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        int cur = 0;
        for(char c: S){
            if(c == '('){
                st.push(cur);
                cur = 0;
            }
            else{
                cur = st.top() + max(2*cur, 1);
                st.pop();
            }
        }
        return cur;
    }
};
