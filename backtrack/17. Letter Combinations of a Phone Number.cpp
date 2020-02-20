//4ms 8.5MB
class Solution {
public:
    vector <string> v = {
        "", "",
        "abc", "def", "ghi", 
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void dfs(int st, vector<string> &res, string &tmp, string &d){
        if(tmp.size() == d.size() && d.size() != 0){
            res.push_back(tmp);
            return;
        }
        for(int i = st; i < d.size(); ++i){
            for(int j = 0; j < v[d[i] - '0'].size(); ++j){
                tmp += v[d[i] - '0'][j];
                dfs(i + 1, res, tmp, d);
                tmp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string tmp = "";
        dfs(0, ans, tmp, digits);
        return ans;
    }
};
