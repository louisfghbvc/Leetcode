// must do equal, then non-equal
// so that is satisfied/
// O(N)

class Solution {
public:
    
    int p[26];
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        p[y] = x;
    }
    
    // two pass, first union equation
    // second check if union non-equal is failed
    // careful must check equal and non-equal, can not swap
    
    bool equationsPossible(vector<string>& equations) {
        memset(p, -1, sizeof p);
        
        for(auto &s: equations){
            if(s[1] == '=')
                uni(s[0]-'a', s[3]-'a');
        }
        
        for(auto &s: equations){
            if(s[1] == '!' && find(s[0] - 'a') == find(s[3] - 'a')) return false;
        }
        
        return true;
    }
};
