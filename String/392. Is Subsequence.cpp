// O(m+n). Just iterate

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int st = 0, cnt = 0;
        for(int i = 0; i < t.size(); ++i){
            if(s[st] == t[i]){
                ++cnt;
                ++st;
            }
        }
        return cnt == s.size() ? true : false;
    }
};
