class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int l = 0;
        int fre[3] = {};
        for(int i = 0; i < s.size(); ++i){
            fre[s[i] - 'a']++;
            while(fre[0] && fre[1] && fre[2]){
                fre[s[l++] - 'a']--;
            }
            res += l;
        }
        return res;
    }
};
