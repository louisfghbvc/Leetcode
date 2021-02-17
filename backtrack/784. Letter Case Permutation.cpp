// Bit magic. small letter want to -32. big want to +32.
// so use XOR.
class Solution {
public:
    vector<string> res;
    void dfs(string &s, int i, string cur){
        if(i == s.size()){
            res.push_back(cur);
            return;
        }
        if(isdigit(s[i]))
           dfs(s, i+1, cur + s[i]);
        else{
            dfs(s, i+1, cur + s[i]);
            dfs(s, i+1, cur + char(s[i] ^ (1<<5)));
        }
    }
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0, "");
        return res;
    }
};
