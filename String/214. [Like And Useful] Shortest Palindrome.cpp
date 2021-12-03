// Z-algorithm O(N)

class Solution {
public:
    
    int build_z(string &s){
        int n = s.size();
        
        vector<int> z(n);
        
        int L = 0, R = 0;
        for(int i = 1; i < n; ++i){
            if(i > R){
                L = R = i;
                while(R < n && s[R] == s[R - L]) R++;
                z[i] = R - L; R--;
            }
            else{
                int k = i - L;
                if(z[k] < R - i + 1) z[i] = z[k];
                else{
                    L = i;
                    while(R < n && s[R] == s[R - L]) R++;
                    z[i] = R - L; R--;
                }
            }
            if(i > n/2 && i + z[i] == n) // must cover index 0, so that's why need to equal to n
                return z[i];
        }
        
        return 0;
    }
    
    string shortestPalindrome(string s) {
        // find the maximum palindrome cover index 0
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        string t = s + "#" + rev_s;
        int max_palindrome = build_z(t);

        return rev_s.substr(0, s.size() - max_palindrome) + s;
    }
};


// use kmp to find longest prefix, suffix
class Solution {
public:
    
    int failure(string &s){
        int n = s.size();
        vector<int> res(n);
        
        for(int j = 1, i = 0; j < n; ++j){
            while(i && s[j] != s[i]) i = res[i-1];
            if(s[i] == s[j]) res[j] = ++i;
        }
        
        return res.back();
    }
    
    string shortestPalindrome(string s) {
        // find the maximum palindrome cover index 0
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        string t = s + "#" + rev_s;
        int max_palindrome = failure(t);

        return rev_s.substr(0, s.size() - max_palindrome) + s;
    }
};

