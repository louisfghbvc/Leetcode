// O(N), space O(1)

class Solution {
public:
    long long helper(string &s, char pat) {
        long long p0 = 0, p1 = 0;
        long ans = 0;
        for (char c: s) {
            if (c == pat) {
                ans += p1;
                p0++;
            }
            else {
                p1 += p0;
            }
        }
        return ans;
    }
    
    long long numberOfWays(string s) {
        // goal: select three building 010 or 101
        // idea: just two pattern : 010 or 101
        // for each pattern, find the number of valid ways

        return helper(s, '0') + helper(s, '1');
    }
};
