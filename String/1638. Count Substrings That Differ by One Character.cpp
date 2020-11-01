// Just Brute Force.
// O(N^4).

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

// O(N^3). Enum all position of s and t. and just compare
class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0, n = s.size();
        for(int i = 0; i < s.size(); ++i){
            for(int j = 0; j < t.size(); ++j){
                int diff = 0;
                for(int pos = 0; i+pos < s.size() && j+pos < t.size(); ++pos){
                    if (s[i + pos] != t[j + pos] && ++diff > 1)
                        break;
                    res += diff;
                }
            }
        }
        return res;
    }
};
