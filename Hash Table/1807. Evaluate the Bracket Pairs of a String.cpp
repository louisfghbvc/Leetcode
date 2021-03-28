// Simple linear scan. O(N).

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        unordered_map<string, string> mp;
        for(auto &kv: knowledge){
            mp[kv[0]] = kv[1];
        }
        
        bool ok = false;
        string t = "";
        for(char c: s){
            if(c == '(') ok = 1;
            else if(c == ')'){
                string add = "?";
                if(mp.count(t)) add = mp[t];
                res += add;
                ok = 0;
                t = "";
            }
            else{
                if(ok) t += c;
                else res += c;
            }
        }
        
        return res;
    }
};
