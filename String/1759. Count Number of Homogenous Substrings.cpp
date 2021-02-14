// O(N) just simple formula.

class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        s += '$';
        long res = 0;
        char prev = 0;
        long fre = 1;
        for(char c: s){
            if(c == prev) fre++;
            else{
                res = (res+(fre+1)*fre/2)%mod;
                fre = 1;
            }
            prev = c;
        }
        return res-1;
    }
};
