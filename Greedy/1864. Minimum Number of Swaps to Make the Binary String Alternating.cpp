// Get answer, and just count different postition.
// Because u don't need change correct pos.
 
class Solution {
public:
    
    int count(string &s, string &ans){
        int n = s.size();
        int cnt[2] = {};
        for(int i= 0; i < n; ++i){
            if(s[i] != ans[i]){
                cnt[s[i]-'0']++;
            }
        }
        if(cnt[0] != cnt[1]) return n+1;
        return cnt[0];
    }
    
    int minSwaps(string s) {
        int n = s.size();
        string ans = "", ans2 = ans;
        bool ch = 0;
        for(int i = 0; i < n; ++i){
            ans += ('1'-ch);
            ch ^= 1;
        }
        
        ch = 1;
        for(int i = 0; i < n; ++i){
            ans2 += ('1'-ch);
            ch ^= 1;
        }
        
        int res = min(count(s, ans), count(s, ans2));
        return res > n ? -1 : res;
    }
};
