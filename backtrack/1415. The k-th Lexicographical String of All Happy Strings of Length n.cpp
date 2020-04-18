//generate all possible.
//132ms 21.8MB
class Solution {
public:
    vector<string> ans;
    void dfs(int i, int &n, string s){
        if(i == n){
            ans.push_back(s);
            return;
        }
        for(char c = 'a'; c <= 'c'; ++c){
            if(s.size() > 0 && s.back() == c) continue;
            dfs(i+1, n, s + c);
        }
        
    }
    string getHappyString(int n, int k) {
        dfs(0, n, "");
        if(k > ans.size())
            return "";
        return ans[k-1];
    }
};
