// O(N). stack. simple, careful case.
class Solution {
public:
    bool match(char a, char b){
        if(a == '{' && b == '}') return 1;
        if(a == '(' && b == ')') return 1;
        if(a == '[' && b == ']') return 1;
        return 0;
    }
    bool isValid(string s) {
        vector<char> st;
        for(char c: s){
            if(c == '(' || c == '{' || c == '[') st.push_back(c);
            else{
                if(st.empty()) return false;
                if(!match(st.back(), c)) return false;
                 st.pop_back();
            }
        }
        return st.empty();
    }
};
