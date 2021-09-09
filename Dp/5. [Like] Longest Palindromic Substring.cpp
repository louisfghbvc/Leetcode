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

// T: O(N^2). S: O(1)
// odd even extend

// Cp manacher. fastest. 8ms
// O(N).
class Solution {
public:
    string longestPalindrome(string s) {
        // manacher
        int n = s.size();
        int res = 0, p1 = 0;

        vector<int> d1(n); // odd
        for(int i = 0, l = 0, r = -1; i < n; ++i){
            int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
            while(i - k >= 0 && i + k < n && s[i + k] == s[i - k]) k++;
            d1[i] = k--;
            if(i + k > r){
                l = i - k;
                r = i + k;
            }
            int len = d1[i] * 2 - 1;
            if(len > res){
                res = len;
                p1 = i;
            }
        }
        
        int res2 = 0, p2 = 0;
        vector<int> d2(n); // even
        for(int i = 0, l = 0, r = -1; i < n; ++i){
            int k = i > r ? 0 : min(d2[l + r - i], r - i + 1); // two mid, can +1
            while(i - k - 1 >= 0 && i + k < n && s[i - 1 - k] == s[i + k]) k++;
            d2[i] = k--;
            if(i + k > r){
                l = i - 1 - k;
                r = i + k;
            }
            int len = d2[i] * 2;
            if(res2 < len){
                res2 = len;
                p2 = i;
            }
        }
        
        return res > res2 ? s.substr(p1 - d1[p1] + 1, d1[p1] * 2 - 1) : s.substr(p2 - d2[p2], d2[p2] * 2);
    }
};
