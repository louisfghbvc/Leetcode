// Use monotonous statergy.
// cuz the lexicographical order must be smallest. so just care back has remain.
// because find a candicate of back char. 
// O(n).

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        int cnt[26] = {};
        bool in[26] = {};
        for(char c: s) cnt[c-'a']++;
        
        string res = "";
        for(char c: s){
            cnt[c-'a']--;
            if(res.empty()){
                res += c;
                in[c-'a'] = 1;
                continue;
            }
            if(in[c-'a']) continue;
            while(res.back() > c && cnt[res.back()-'a'] > 0){
                in[res.back()-'a'] = 0;
                res.pop_back();
            }
            in[c-'a'] = 1;
            res += c;
        }
        
        return res;
    }
};
