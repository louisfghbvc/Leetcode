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
