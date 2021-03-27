// Each center extand palindrome. O(N^2)

class Solution {
public:
    int cnt = 0;
    
    void extand(string &s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            cnt++;
            l--;
            r++;
        }
    }
    
    int countSubstrings(string s) {
        for(int i = 0; i < s.size(); ++i){
            extand(s, i, i);
            extand(s, i, i+1);
        }
        return cnt;
    }
};

// Manacher O(N).
class Solution {
public:

    int countSubstrings(string s) {
        string t = "^#";
        for(char &c: s){
            t += c;
            t += '#';
        }
        t += '$';

        int n = t.size();
        vector<int> dp(n);
        int C = 0, R = 0;
        // manacher
        for(int i = 1; i+1 < n; ++i){
            int mir = 2*C-i;
            if(mir > 1 && i + dp[mir] < R){
                dp[i] = dp[mir];
                continue;
            }
            while(t[i - 1 - dp[i]] == t[i + 1 + dp[i]]) dp[i]++;
            if(i + dp[i] > R){
                R = i+dp[i];
                C = i;
            }
        }
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            res += (dp[i]+1)/2;
        }
        
        return res;
    }
};
