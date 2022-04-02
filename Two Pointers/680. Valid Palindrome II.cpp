// two pointers
// Time: O(N), Space: O(1)

class Solution {
public:
    
    bool isPalindrome(string &s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        // delete at most 1
        // idea: move l=0, r=s.size()-1;
        // check until s[l] != s[r], either move l or move 2
        
        int l = 0, r = (int)s.size()-1;
        while (l <= r) {
            if (s[l] != s[r]) break;
            l++;
            r--;
        }
        
        return isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1);
    }
};
