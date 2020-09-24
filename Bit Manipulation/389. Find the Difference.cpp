// Same as single number.
// O(N). x^x = 0.

class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            res ^= s[i];
            res ^= t[i];
        }
        res ^= t.back();
        return (char)res;
    }
};
