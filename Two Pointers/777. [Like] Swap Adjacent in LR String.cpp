// record index, and is easy to calculate the L must can be sliding
// also R
// O(N)

class Solution {
public:
    // start = {(R, 0), (L, 3), (R, 4), (R, 6), (L, 8) }
    // end = {(R, 1), (L, 2), (R, 5), (R, 6), (L, 7) }
    
    vector<pair<char, int>> filterLR(string &s){
        vector<pair<char, int>> res;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'L' || s[i] == 'R')
                res.push_back({s[i], i});
        }
        return res;
    }
    
    bool canTransform(string start, string end) {
        auto a = filterLR(start);
        auto b = filterLR(end);
        if(a.size() != b.size()) return false;
        
        for(int i = 0; i < a.size(); ++i){
            if(b[i].first != a[i].first) return false;
            
            if(b[i].first == 'R'){
                if(a[i].second > b[i].second) return false;
            }
            else{
                if(a[i].second < b[i].second) return false;
            }
        }
        
        return true;
    }
};
