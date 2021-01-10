// Only two choice. so just greedy. 
// and substring can not get more. same abab.
// O(N).
class Solution {
public:
    
    int maximumGain(string s, int x, int y) {
        string a = "ab", b = "ba";
        if(x < y) swap(a, b), swap(y, x);
        int res = 0;
        
        string t = "";
        for(char &c: s){
            if(t.size() && t.back() == a[0] && c == a[1]){
                t.pop_back();
                res += x;
            }
            else t += c;
        }
        
        string ts = "";
        for(char &c: t){
            if(ts.size() && ts.back() == b[0] && c == b[1]){
                ts.pop_back();
                res += y;
            }
            else ts += c;
        }
        
        return res;
    }
};
