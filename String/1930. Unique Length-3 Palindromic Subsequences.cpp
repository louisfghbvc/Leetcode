// Only 26*26 possibles. so we use array.
// O(26*n). like suffix and prefix. and enumerate.
class Solution {
public:
    int N = 26*26;
    int countPalindromicSubsequence(string s) {
        vector<int> res(N);
        int n = s.size();
        
        vector<int> right(26);
        for(int i = n-1; i >= 0; --i){
            right[s[i] - 'a']++;
        }
        
        vector<bool> left(26);
        left[s[0] - 'a'] = 1;
        right[s[0] - 'a']--;
        for(int i = 1; i+1 < n; ++i){
            right[s[i]-'a']--;
            for(int k = 0; k < 26; ++k){
                if(left[k] && right[k]){
                    int t = (s[i]-'a')*26 + k;
                    res[t] = 1; 
                }
            }
            left[s[i] - 'a'] = 1;
        }
        
        int cnt = 0;
        for(int i = 0; i < N; ++i) if(res[i]) cnt++; 
        
        return cnt;
    }
};
