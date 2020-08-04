// track count. use count sort.
// O(NW).

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        int fre[26] = {};
        for(auto &c: chars) fre[c-'a']++;
        for(auto &s: words){
            int tmp[26] = {};
            memcpy(tmp, fre, sizeof fre);
            bool ok = 1;
            for(auto &c: s) if(--tmp[c-'a'] < 0){
                ok = 0; break;
            }
            res += ok ? s.size() : 0;
        }
        return res;
    }
};
