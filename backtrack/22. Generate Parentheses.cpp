class Solution {
public:
    void dfs(string s, int l, int r, vector<string> &res){
        if(l == 0 && r == 0){
            res.push_back(s);
            return;
        }
        if(r > 0)
            dfs(s + ')', l, r - 1, res);
        if(l > 0)
            dfs(s + '(', l - 1, r + 1, res);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs("", n, 0, ans);
        return ans;
    }
};
