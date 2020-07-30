// So Clean. QQ not come up with this question...
// so dp can memo the index vector<string>. because. duplicate.
// and just like merge and merge, from small to big.
// Memorize magic. 

class Solution {
public:
    unordered_set<string> dc;
    unordered_map<int, vector<string>> memo;
    string s;
    vector<string> dfs(int idx){
        if(memo.count(idx)) return memo[idx];
        string cur = "";
        vector<string> res;
        for(int i = idx; i < s.size(); ++i){
            cur += s[i];
            if(dc.count(cur)){
                if(i == s.size() - 1) res.push_back(cur);
                vector<string> suff = dfs(i+1);
                for(auto &e: suff) res.push_back(cur + " " + e);
            }
        }
        return memo[idx] = res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        dc =  unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(0);
    }
};
