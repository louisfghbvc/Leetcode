// O(N).

class Solution {
public:
    int longestSubsequence(string s, int k) {
        // goal: find the longest subsequence that number is smaller or equal to k
        // observe that number of zero is the ans -> base case
        
        int ans = count(s.begin(), s.end(), '0');
        
        // idea: greedy, from right to left
        
        int num = 0, n = s.size(); // zero cnt
        long val = 0;
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == '1') {
                if (num <= 31 && (val+(1LL<<num)) <= k) {
                    val += 1LL<<num;
                    num++;
                }
            }
            else {
                num++;
            }
            ans = max(ans, num);
        }
        
        return ans;
    }
};
