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


// check palindrome use dp. O(N2^N)
class Solution {
public:
    
    vector<vector<string>> res;
    int n;
    string s;
    bool dp[17][17];
    
    void dfs(int l, vector<string> &tmp){
        if(l >= n){
            res.push_back(tmp);
            return;
        }
        for(int r = l; r < n; ++r){
            if(s[l] == s[r] && (r-l <= 2 || dp[l+1][r-1])){
                dp[l][r] = 1;
                tmp.push_back(s.substr(l, r-l+1));
                dfs(r+1, tmp);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        this->s = s;
        n = s.size();
        vector<string> tmp;
        dfs(0, tmp);
        return res;
    }
};
