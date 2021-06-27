// O(N^2). BF.

class Solution {
public:
    
    bool isEQ(string &s, string &p, int l, int r){
        for(int i = l, j = 0; i <= r; ++i, ++j){
            if(p[j] != s[i]) return false;
        }
        return true;
    }
    
    string removeOccurrences(string s, string part) {
        int ps = part.size(); 
        string res = "";
        
        for(char c: s){
            res += c;
            if(res.size() >= ps){
                if(isEQ(res, part, res.size()-ps, res.size()-1))
                    res.erase(res.begin() + res.size()-ps, res.end());
                
            }
        }
        
        return res;
    }
};

// O(N^2). clean
class Solution {
public:
    string removeOccurrences(string s, string part) {
        auto it = s.find(part);
        while(it != -1){
            s.erase(it, part.size());
            it = s.find(part);
        } 
        return s;
    }
};


// O(N). KMP.
// TODO
