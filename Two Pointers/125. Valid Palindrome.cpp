// O(N). Simple just two pointer and compare.
// isalnum() is cool!
class Solution {
public:
    bool isPalindrome(string s) {
        for(int l = 0, r = s.size()-1; l < r; l++, r--){
            while(!isalnum(s[l]) && l < r) l++;
            while(!isalnum(s[r]) && l < r) r--;
            if(tolower(s[l]) != tolower(s[r])) return false;
        }
        return true;
    }
};
