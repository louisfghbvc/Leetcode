// Convert to graph problem O(N^22^N). tricky.
// and do tsp.

class Solution {
public:
    
    bool startWith(string &s, string &t){
        if(s.size() > t.size()) return false;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != t[i]) return false;
        }
        return true;
    }
    
    int dis(string &a, string &b){
        for(int i = 1; i < a.size(); ++i){
            string asuf = a.substr(i);
            if(startWith(asuf, b))
                return asuf.size();
        }
        return 0;
    }
    
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        
        vector<vector<int>> g(n, vector<int>(n));
        
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                g[i][j] = dis(words[i], words[j]);
                g[j][i] = dis(words[j], words[i]);
            }
        }
        
        // dp[i][mask] last pos, mask
        vector<vector<string>> dp(n, vector<string>(1<<n)); 
        
        // init
        for(int i = 0; i < n; ++i) dp[i][1<<i] += words[i];
        
        for(int S = 1; S < (1<<n); ++S){
            for(int j = 0; j < n; ++j) if(S >> j & 1){
                for(int i = 0; i < n; ++i) if(i != j && (S >> i & 1)){
                    string tmp = dp[i][S ^ (1<<j)] + words[j].substr(g[i][j]); // i to j
                    if(dp[j][S].empty() || dp[j][S].size() > tmp.size()){
                        dp[j][S] = tmp;
                    }
                }
            }
        }
        
        string res = dp[0].back();
        for(int i = 1; i < n; ++i){
            if(res.size() > dp[i].back().size())
                res = dp[i].back();
        }
        
        return res;
    }
};
