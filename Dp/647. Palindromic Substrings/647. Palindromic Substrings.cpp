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
            if(mir >= 1 && i + dp[mir] < R){
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

class Solution {
public:
    
    int countSubstrings(string s) {
        // goal: count the substring that is palindrome
        // idea: manacher
        
        int n = s.size();
        int ans = 0;
        
        vector<int> d1(n); // odd
        vector<int> d2(n); // even
        // d1[i]: length of palindrome from index i of half 
        // d2[i]: length of palindrome from index i and i-1
        
        for(int i = 0, l = 0, r = -1; i < n; ++i){
            int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
            while(i - k >= 0 && i + k < n && s[i + k] == s[i - k]) k++;
            d1[i] = k--;
            if(i + k > r){
                l = i - k;
                r = i + k;
            }
            ans += d1[i];
        }
        
        for(int i = 0, l = 0, r = -1; i < n; ++i){
            int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1); // !!! l-r+i+1, must add 1
            while(i - k - 1 >= 0 && i + k < n && s[i - 1 - k] == s[i + k]) k++;
            d2[i] = k--;
            if(i + k > r){
                l = i - 1 - k;
                r = i + k;
            }
            ans += d2[i];
        }
        
        return ans;
    }
};
