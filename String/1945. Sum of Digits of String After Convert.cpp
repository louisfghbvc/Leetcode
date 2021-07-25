class Solution {
public:
    
    int SS(int x){
        int cnt = 0;
        while(x){
            cnt += x%10;
            x/=10;
        }
        return cnt;
    }
    
    int getLucky(string s, int k) {
        string t = "";
        for(char c: s){
            t += to_string(c - 'a' + 1);
        }
        int res = 0;
        if(k--){
            for(int i = 0; i < t.size(); ++i){
                res += t[i] - '0';
            }
        }
        while(k--){
            res = SS(res);
        }
        return res;
    }
};
