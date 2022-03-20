// greedy, O(N)

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        // goal: add the pattern[0] or pattern[1] to the text
        // idea: only add p[0] to begin or p[1] to the end
        
        // add p[0] to begin
        long ans1 = 0;
        long cnt = 1;
        for (char c: text) {
            if (c == pattern[1]) 
                ans1 += cnt;
            cnt += pattern[0] == c;
        }
        
        // add p[1] to end
        long ans2 = 0;
        cnt = 0;
        for (char c: text) {
            if (c == pattern[1]) 
                ans2 += cnt;
            cnt += pattern[0] == c;
        }
        ans2 += cnt;
        
        return max(ans2, ans1);
    }
};
