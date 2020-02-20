//4ms 9.5MB
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int mx = 0;
        vector<int> dp = {0};
        for(auto s : arr){
            int a = 0;
            for(char c : s)
                a |= (1 << (c - 'a'));
            int n = __builtin_popcount(a);
            if(n < s.size()) continue;
            
            for(int i = dp.size() - 1; i >= 0; --i){
                int pre = dp[i];
                if(pre & a) continue;
                dp.push_back(pre | a);
                mx = max(mx, __builtin_popcount(pre | a));
            }
        }
        return mx;
    }
};
