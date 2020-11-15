// OK... Greedy. but here use prefix and suffix. record all possible erase fre.
// O(N). not optimal

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> pre(n+1), suf(n+1);
        
        pre[0] = 0;
        for(int i = 0; i < n; ++i){
            pre[i+1] = pre[i] + (s[i] == 'b');
        }
        
        suf[n] = 0;
        for(int i = n-1; i >= 0; --i){
            suf[i] = suf[i+1] + (s[i] == 'a');
        }
        
        int res = 1e9;
        for(int i = 0; i <= n; ++i) res = min(res, pre[i]+suf[i]);
        
        return res;
    }
};

// Improve. Greedy.
