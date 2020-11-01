// Just Brute Force.
// O(N^3).

class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0, n = s.size();
        for(int i = 0; i < n; ++i){
            string tmp = "";
            for(int j = i; j < n; ++j){
                tmp += s[j];
                for(int k = 0; k-1+tmp.size() < t.size(); ++k){
                    int d = 0;
                    for(int l = 0; l < tmp.size(); ++l){
                        if(tmp[l] != t[k+l]) d++;
                    }
                    res += d==1;
                }
            }
        }
        return res;
    }
};

