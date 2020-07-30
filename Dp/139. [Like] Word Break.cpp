// Same idea more easier. just like word break II
// Dp + memorize

class Solution {
public:
    string s;
    unordered_set<string> dc;
    unordered_map<int, bool> dp;
    bool dfs(int idx){
        if(idx == s.size()) return 1;
        if(dp.count(idx)) return dp[idx];
        string cur = "";
        bool res = 0;
        for(int i = idx; i < s.size(); ++i){
            cur += s[i];
            if(dc.count(cur)){
                res |= dfs(i+1);
            }
        }
        return dp[idx] = res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dc = unordered_set<string>(wordDict.begin(), wordDict.end());
        this->s = s;
        return dfs(0);
    }
};
