class Solution {
public:
    int longestContinuousSubstring(string s) {
        // goal: find the longest 'a'-'z'
        // idea: for each index try to match the 'a' to 'z'
        // at most 26
        
        
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int j = i;
            while (j < n && s[j] == s[i]+j-i)
                j++;
            ans = max(ans, j-i);
        }
        return ans;
    }
};
