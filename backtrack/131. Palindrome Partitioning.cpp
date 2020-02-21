//12ms 12.4MB
class Solution {
public:
    bool isP(string &s, int l, int r){
        while(l <= r){
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void dfs(int st, vector<vector<string>> &res, vector<string> &tmp, string &s){
        if(st == s.size()){
            res.push_back(tmp);
            return;
        }
        for(int i = st; i < s.size(); ++i){
            if(isP(s, st, i)){
                tmp.push_back(s.substr(st, i - st + 1));
                dfs(i + 1, res, tmp, s);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(0, res, tmp, s);
        return res;
    }
};
