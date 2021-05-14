// BF. Enum left, right. and check valid.

class Solution {
public:
    
    vector<string> gen(string t){
        vector<string> res = {t};
        for(int i = 1; i < t.size(); ++i){
            res.push_back(t.substr(0, i) + "." + t.substr(i));
        }
        return res;
    }
    
    bool valid(string &t){
        if(t.empty()) return false;
        if(t.size() == 1) return true;
        
        // head with dummy zero
        if(t[0] == '0' && t[1] != '.') return false;
        
        // tail with dummy zero, and has .
        bool hasDot = false;
        for(char c : t) if(c == '.') hasDot = 1;
        if(!hasDot) return true;
        
        return t.back() != '0';
    }
    
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        
        for(int i = 1; i+2 < s.size(); ++i){
            string l = s.substr(1, i);
            string r = s.substr(1+i); r.pop_back();
            vector<string> left = gen(l);
            vector<string> right = gen(r);
            
            for(auto &tl: left){
                for(auto &tr: right){
                    if(valid(tl) && valid(tr)){
                        res.push_back("(" + tl + ", " + tr + ")");
                    }
                }
            }
            
        }        
        
        return res;
    }
};
