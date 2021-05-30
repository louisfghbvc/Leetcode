class Solution {
public:
    string maxValue(string n, int x) {
        bool neg = (n[0] == '-');
        int i = neg;
        string res = string(neg, '-');
        if(neg){
            bool f = 0;
            for(; i < n.size(); ++i){
                if(n[i] - '0' > x && !f){
                    res += string(1, '0' + x);
                    f = 1;
                }
                res += n[i];
            }
            if(!f) res += string(1, '0' + x);
        }
        else{
            bool f = 0;
            for(; i < n.size(); ++i){
                if(n[i] - '0' < x && !f){
                    res += string(1, '0' + x);
                    f = 1;
                }
                res += n[i];
            }
            if(!f) res += string(1, '0' + x);
        }
        
        return res;
    }
};
