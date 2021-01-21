class Solution {
public:
    
    bool dp[1001][1001];

    string longestPalindrome(string s) {
        if(s.size() == 0)
            return "";
        int l = 0, r = 0;
        for(int i = 0; i < s.size(); ++i){
            dp[i][i] = true;
        }
        for(int i = 0; i < s.size() - 1; ++i){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                l = i;
                r = i + 1;
            }
        }
        for(int len = 2; len < s.size(); ++len){
            for(int i = 0; i + len< s.size(); ++i){
                if(s[i] == s[i + len] && dp[i + 1][i + len - 1]){
                    dp[i][i + len] = true;
                    l = i;
                    r = i + len;
                }
                else{
                    dp[i][i + len] = false;
                }
            }
        }
        return s.substr(l, r - l + 1);
    }
};

// O(N). Manacher's Algorithm. Tricky.
// just concern i or i + dp[mir] is in R.
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for(char c: s){
            t += c;
            t += "#";
        }
        t += '^';
        int n = t.size();
        
        vector<int> dp(n);
        int C = 0, R = 0;
        int mx = 0, mxi = 0;
        
        for(int i = 1; i+1 < n; ++i){
            int mir = 2*C-i;
            if(i < R && mir >= 1 && (i + dp[mir]) < R){
                dp[i] = dp[mir];
                continue;
            }
            while(t[i - 1 - dp[i]] == t[i + 1 + dp[i]]) dp[i]++;
            
            if(i + dp[i] > R){
                R = i+dp[i];
                C = i;
            }
            
            if(dp[i] > mx){
                mx = dp[i];
                mxi = i;
            }
        }
        
        return s.substr((mxi - mx)/2, mx);
    }
};
