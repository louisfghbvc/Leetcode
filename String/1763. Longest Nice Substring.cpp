// O(N^2).

class Solution {
public:
    bool ok(set<char> &a, set<char> &b){
        for(char c: a){
            if(!b.count(c-'a' + 'A')) return false;
        }
        for(char c: b){
            if(!a.count(c-'A' + 'a')) return false;
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        string res = "";
        for(int i = 0; i < s.size(); ++i){
            string t = "";
            set<char> sm, big;
            for(int j = i; j < s.size(); ++j){
                if(islower(s[j])) sm.insert(s[j]);
                else big.insert(s[j]);
                t += s[j];
                if(t.size() > res.size() && ok(sm, big)){
                    res = t;
                }
            }
        }
        return res;
    }
};
