// memo. O(N^2).
class Solution {
public:
    unordered_map<string, vector<int>> dp;
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }
    
    vector<int> dfs(string s){
        if(dp.count(s)) return dp[s];
        vector<int> res;
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            if(c == '+' || c == '-' || c == '*'){
                vector<int> left = diffWaysToCompute(s.substr(0, i));
                vector<int> right = diffWaysToCompute(s.substr(i+1));
                
                for(int l: left){
                    for(int r: right){
                        if(c == '+')
                            res.push_back(l + r);
                        else if(c == '-')
                            res.push_back(l - r);
                        else
                            res.push_back(l * r);
                    }
                }
            }
        }
        if(res.size() == 0) res.push_back(stoi(s));
        return dp[s] = res;
    }
};


// BF just recursive can pass
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for(int i = 0; i < expression.size(); ++i){
            char c = expression[i];
            if(c == '+' || c == '-' || c == '*'){
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                
                for(int l: left){
                    for(int r: right){
                        if(c == '+')
                            res.push_back(l + r);
                        else if(c == '-')
                            res.push_back(l - r);
                        else
                            res.push_back(l * r);
                    }
                }
            }
        }
        if(res.size() == 0) res.push_back(stoi(expression));
        return res;
    }
};
