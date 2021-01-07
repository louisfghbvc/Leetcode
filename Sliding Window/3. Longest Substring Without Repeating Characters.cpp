// O(N). Simple silding window stragery.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int fre[256] = {};
        for(int r = 0, l = 0; r < s.size(); ++r){
            int c = s[r];
            fre[c]++;
            while(fre[c] > 1) fre[s[l++]]--;
            res = max(res, r-l+1);
        }
        return res;
    }
};

// also no use array.
