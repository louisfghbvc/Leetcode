// Solution1 simple backtracking.
class Solution {
public:
    vector<string> ans;
    void dfs(int c, string s, int n, int i){
        if(i == 2*n){
            if(c == 0) ans.push_back(s); 
            return;
        } 
        if(c < 0) dfs(c+1, s+")", n, i+1);
        dfs(c-1, s+"(", n, i+1);
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        dfs(0, "", n, 0);
        return ans;
    }
};

// Solution2 dp + backtracking, very cool
// f(0) = ""
// f(1) = (f(0))
// f(2) = (f(0))f(1) or (f(1))
// f(3) = (f(0))f(2) ot (f(2))
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0){
            ans.push_back("");
        }
        else{
            for(int c = 0; c < n; ++c)
                for(const auto& left: generateParenthesis(c))
                    for(const auto& right: generateParenthesis(n - c - 1))
                        ans.push_back("(" + left + ")" + right);
        }
        return ans;
    }
};
