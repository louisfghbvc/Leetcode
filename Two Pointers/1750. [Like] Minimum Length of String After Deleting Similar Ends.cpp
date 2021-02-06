// just two pointers. clean O(N). WA 2 times.QQ
class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size()-1;
        while(l < r && s[l] == s[r]){
            char me = s[l];
            while(l <= r && s[l] == me) l++;
            while(l <= r && me == s[r]) r--;
        }
        return r-l+1;
    }
};
