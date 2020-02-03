class Solution {
    bool isUpper(char c){
        if(c >= 'A' && c <= 'Z')
            return true;
        return false;
    }
    void dfs(vector<string> &res, string t, string &s, int i, int &len){
        if(i == len){
            res.push_back(t);
            return;
        }
        if(s[i] >= '0' && s[i] <= '9'){
            dfs(res, t+s[i], s, i+1, len);
            return;
        }
        if(isUpper(s[i])) 
            s[i] = s[i] - 'A' + 'a';
        dfs(res, t + (char)(s[i]-'a' + 'A'), s, i+1, len);
        dfs(res, t + s[i], s, i+1, len);
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        int n = S.size();
        dfs(ans, "", S, 0, n);
        return ans;
    }
};
