class Solution {
public:
    vector<string> validStrings(int n) {
        // goal: return all possible valid string such that 
        
        vector<string> res;
        
        string tmp;
        auto dfs = [&](auto &self, int i, char last='2') -> void {
            if (i >= n) {
                res.push_back(tmp);
                return;
            }
            
            for (char c = '0'; c <= '1'; ++c) {
                if (last != '0' || last == '0' && c == '1') {
                    tmp.push_back(c);
                    self(self, i+1, c);
                    tmp.pop_back();
                }
            }
            
        };
        
        dfs(dfs, 0);
        
        return res;
    }
};
