// O(N). Simulate. just make no repeat char.

class Solution {
public:
    string modifyString(string s) {
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != '?') continue;
            char l = '?', r = '?';
            if(i) l = s[i-1];
            if(i+1 < s.size()) r = s[i+1];
            for(int k = 0; k < 26; ++k) if((k+'a') != l && (k+'a') != r){
                s[i] = (k+'a');
                break;
            } 
        }
        return s;
    }
};
