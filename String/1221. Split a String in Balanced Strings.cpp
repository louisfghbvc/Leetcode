//0ms 8.6MB
class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, lcnt = 0, rcnt = 0; 
        for(int i = 0; i < s.size(); ++i){
            s[i] == 'L' ? lcnt++ : rcnt++;
            if(lcnt == rcnt && lcnt + rcnt){
                lcnt = rcnt = 0;
                res++;
            }
        }
        return res;
    }
};
