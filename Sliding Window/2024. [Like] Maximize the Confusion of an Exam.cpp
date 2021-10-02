// Just maintain window at most k different either `T` or `F`
// O(N)

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int res = 1;
        map<char, int> cnt;
        int len = 0;
        for(int l = 0, r = 0; r < n; ++r){
            cnt[s[r]]++;
            len++;
            while(max(cnt['T'], cnt['F']) + k < len){
                len--;
                cnt[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        
        return res;
    }
};
