//Simulate. 28ms 24MB.
class Solution {
public:
    int numSteps(string s) {
        if(s.back() == '1' && s.size() == 1) return 0;
        
        if(s.back() == '1'){
            bool fz = 0;
            for(int i = s.size() - 1; i >= 0; --i){
                if(s[i] == '1') s[i] = 0;
                else{
                    s[i] = '1';
                    fz = 1;
                    break;
                }
            }
            if(!fz) s.insert(s.begin(), '1');
            return 1 + numSteps(s);
        }
        s.pop_back();
        return 1 + numSteps(s);
    }
};
