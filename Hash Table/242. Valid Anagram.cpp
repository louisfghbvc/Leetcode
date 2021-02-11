// O(N).
class Solution {
public:
    bool isAnagram(string s, string t) {
        char fre[128] = {};
        for(char c: s) fre[c]++;
        for(char c: t) --fre[c];
        for(int i = 0; i < 128; ++i) if(fre[i]) return false;
        return true;
    }
};
