class Solution {
public:
    
    int conv(string &s) {
        return stoi(s.substr(0, 2))*60 + stoi(s.substr(3));
    }
    
    int countTime(string time) {
        // goal: try to replace ? to 0-9
        // idea: backtracking
        
        vector<char> bound = {'2', '9', '0', '5', '9'};
        
        int ans = 0;
        auto dfs = [&](auto &self, int i) {
            if (i == time.size()) {
                int t = conv(time);
                ans += t >= 0 && t < 24*60;
                return;
            }    
            if (time[i] != '?' || i == 2) 
                self(self, i+1);
            else {
                for (char c = '0'; c <= bound[i]; ++c) {
                    time[i] = c;
                    self(self, i+1);
                    time[i] = '?';
                }
            }
        };
        
        dfs(dfs, 0);
        return ans;
    }
};
