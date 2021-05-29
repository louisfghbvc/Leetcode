class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int res = 0, n = s.size();
        for(int i = 0; i+3 <= n; ++i){
            string tmp = s.substr(i, 3);
            res += (tmp[0] != tmp[1] && tmp[1] != tmp[2] && tmp[0] != tmp[2]);
        }
        return res;
    }
};
