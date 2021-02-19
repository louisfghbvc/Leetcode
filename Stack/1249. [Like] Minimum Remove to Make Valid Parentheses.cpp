// Record bad index of that parentheses. O(N).

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(st.empty() || s[st.top()] != '(') st.push(i);
                else st.pop();
            }
        }
        
        while(st.size()){
            s[st.top()] = '*'; st.pop();
        }
        
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '*') continue;
            res += s[i];
        }
        
        return res;
    }
};

// same idea but use extra set.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(st.empty() || s[st.top()] != '(') st.push(i);
                else st.pop();
            }
        }
        set<int> bad;
        while(st.size()){
            bad.insert(st.top()); st.pop();
        }
        
        for(int i = 0; i < s.size(); ++i){
            if(bad.count(i)) continue;
            res += s[i];
        }
        
        return res;
    }
};
