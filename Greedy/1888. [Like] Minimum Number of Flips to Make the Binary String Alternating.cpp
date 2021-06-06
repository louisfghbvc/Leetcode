// O(N). Greedy + Sliding window + Prefix sum. like conv

class Solution {
public:
    
    int minFlips(string s) {
        int od = s.size();
        s += s;
        int n = s.size();
        
        string ans = "";
        bool f = 0;
        for(int i = 0; i < n; ++i){
            ans += '0' + f;
            f ^= 1;
        }
        
        string ans1 = "";
        f = 1;
        for(int i = 0; i < n; ++i){
            ans1 += '0' + f;
            f ^= 1;
        }
        
        vector<int> pre1(n+1), pre2(n+1);
        for(int i = 1; i <= n; ++i){
            pre1[i] += pre1[i-1] + (ans[i-1] != s[i-1]);
            pre2[i] += pre2[i-1] + (ans1[i-1] != s[i-1]);
        }
        
        int res = 1e9;
        for(int i = 0; i+od <= n; ++i){
            res = min(res, pre1[i+od] - pre1[i]);
            res = min(res, pre2[i+od] - pre2[i]);
        }
        
        return res;
    }
};
