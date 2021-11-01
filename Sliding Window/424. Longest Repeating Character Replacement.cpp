// Only record maximum, not need to enum all uppercase.
// O(N).
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> fre(26); // frequency
        
        int res = 0;
        int mx_cnt = 0;
        for(int r = 0, l = 0; r < s.size(); ++r){
            mx_cnt = max(mx_cnt, ++fre[s[r] - 'A']);
            // not good, if k is not enough
            while(r - l + 1 - mx_cnt > k){
                fre[s[l] - 'A']--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};


// O(26N).
class Solution {
public:
    
    // return longest length can change use char
    int helper(string &s, int k, char change){
        int res = 0;
        
        int cnt = 0;
        // maintain window size is good
        for(int r = 0, l = 0; r < s.size(); ++r){
            cnt += s[r] == change;
            
            // not good
            while(r - l + 1 - cnt > k){
                cnt -= s[l] == change;
                l++;
            }
            
            res = max(res, r-l+1);
        }
        
        return res;
    }
    
    int characterReplacement(string s, int k) {
        int res = 0;
        
        // try to change each uppercase letter
        // only change same type, since we want longest same letter
        for(int i = 0; i < 26; ++i){
            res = max(res, helper(s, k, 'A'+ i));
        }
        
        return res;
    }
};
