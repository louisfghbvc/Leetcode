//O(N) 0ms 6.1MB
//Maintain a min, max open.
class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(')
                cmin++, cmax++;
            else if(s[i] == ')')
                cmax--, cmin = max(0, cmin-1);
            else
                cmax++, cmin = max(0, cmin-1);
            if(cmax < 0) return 0;
        }
        return cmin == 0;
    }
};
