class Solution {
public:
    bool checkIfPangram(string sentence) {
        int fre[26] = {};
        for(char c: sentence) fre[c - 'a']++;
        for(int i = 0; i < 26; ++i)
            if(fre[i] < 1) return false;
        return true;
    }
};
