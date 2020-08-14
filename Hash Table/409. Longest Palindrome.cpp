// use array to map fre. 
// just odd time add even. and 1.
class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[52] = {};
        for(char c: s) islower(c) ? cnt[c-'a']++ : cnt[c-'A'+26]++;
        int res = 0, odd = 0;
        for(int i = 0; i < 52; ++i){
            if(cnt[i] % 2 == 0){
                res += cnt[i];
            }
            else{
                odd = 1;
                res += cnt[i]-1;
            }
        }
        return res + odd;
    }
};

// Python 1 line
class Solution:
    def longestPalindrome(self, s: str) -> int:
        return len(s) - max(0, sum(v&1 for v in Counter(s).values()) - 1)
