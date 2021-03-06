// O(N^2). Counting sort.

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; ++i){
            int fre[26] = {};
            for(int j = i; j < n; ++j){
                fre[s[j]-'a']++;
                int mx = 0, mn = 1e9;
                for(int k = 0; k < 26; ++k){
                    if(!fre[k]) continue;
                    mx = max(mx, fre[k]);
                    mn = min(mn, fre[k]);
                }
                if(mx < mn) continue;
                res += mx - mn;
            }
        }
        return res;
    }
};
