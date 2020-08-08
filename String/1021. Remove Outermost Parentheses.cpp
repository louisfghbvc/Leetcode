// O(N). just when zero means that are outermost
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        int n = S.size();
        int c = 0, l = 0;
        for(int i = 0; i < n; ++i){
            c += S[i] == '(' ? -1 : +1;
            if(c == 0){
                res += S.substr(l+1, i-l-1);
                l = i+1;
            }
        }
        return res;
    }
};

// Optimal. 
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        int cnt = 0;
        for(auto &c: S){
            if(c == '(' && cnt++ > 0) res += '(';
            if(c == ')' && --cnt > 0) res += ')';
        }
        return res;
    }
};
