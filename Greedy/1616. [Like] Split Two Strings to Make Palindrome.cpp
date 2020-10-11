// Clean, Need a nice observation.
// check aprefix == bsuffix. and check remain each is palindrome
// O(N). 72ms.

class Solution {
public:
    bool isP(string &s, int l, int r){
        while(l < r && s[l] == s[r])
            l++, r--;
        return l >= r;
    }
    bool pal(string &a, string &b){
        int n = a.size();
        int l = 0, r = n-1;
        while(l < r && a[l] == b[r])
            l++, r--;
        return isP(a, l, r) || isP(b, l, r);
    }
    bool checkPalindromeFormation(string a, string b) {
        return pal(a, b) || pal(b, a);
    }
};

// From middle. O(N).
class Solution {
public:
    bool isP(string s){
        int n = s.size();
        for(int i = 0; i <= n/2; ++i){
            if(s[i] != s[n-1-i]) return false;
        }
        return true;
    }
    bool pal(string &a, string &b){
        int n = a.size();
        int l, r;
        if(n & 1) l = n/2, r = n/2; 
        else l = n/2-1, r = n/2;
        while(l >= 0 && r < n){
            if(a[l] == a[r]) l--, r++;
            else break;
        }
        string ap = a.substr(0, l+1), as = a.substr(r);
        string bp = b.substr(0, l+1), bs = b.substr(r);
        return isP(ap+bs) || isP(bp+as);
    }
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();
        if(isP(a) || isP(b)) return true;
        return pal(a, b) || pal(b, a);
    }
};
