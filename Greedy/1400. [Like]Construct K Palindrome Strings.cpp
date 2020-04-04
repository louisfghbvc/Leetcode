//tricky. odd count can be a palindrome. even ignore
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()) return 0;
        int fre[26] = {};
        for(auto &c: s) fre[c-'a']++;
        int p = 0;
        for(int i = 0; i < 26; ++i){
            if(fre[i] & 1) p++;
        }
        return p <= k;
    }
};
