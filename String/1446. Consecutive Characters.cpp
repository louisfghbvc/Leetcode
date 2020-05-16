// Simple count fre. One pass.
class Solution {
public:
    int maxPower(string s) {
        int mx = 1, fre = 1;
        char c = s[0];
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == c){
                fre++;
            }
            else{
                c = s[i];
                fre = 1;
            }
            mx = max(mx, fre);
        }
        return mx;
    }
};
