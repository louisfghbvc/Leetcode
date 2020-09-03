// well... just brute force can pass...
// K = N's factor number. the factor number is very small.
// O(KN).

class Solution {
    bool check(string &s, int len){
        string subs = s.substr(0, len);
        int b = s.size() / len;
        string tmp = "";
        for(int i = 0; i < b; ++i){
            tmp += subs;
        }
        return tmp == s;
    }
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i <= n / 2; ++i){
            if(n % i == 0){
                if(check(s, i))
                    return true;
            }
        }
        return false;
    }
};

// O(N). Kmp. well I used to build lps table. it's a uva classic problem
// if lps == 0, means no prefix and suffix.
// n - lps is the minimum cycle can build string S
class Solution {
public:
    int lps(string &s){
        int n = s.size();
        vector<int> lp(n);
        for(int j = 1, i = 0; j < n; ++j){
            while(s[i] != s[j] && i > 0) i = lp[i-1];
            if(s[i] == s[j]) lp[j] = ++i;
        }
        return lp.back();
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int longest_ps = lps(s);
        if(!longest_ps) return false;
        int len = n - longest_ps;
        return n % len == 0;
    }
};
