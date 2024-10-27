class Solution {
public:
    int possibleStringCount(string word, int k) {
        // goal: find the total string such that at least length k
        // idea:
        // can we compute the total length?
        // can we now num of string < k
        // group the letter
        // consider dp
        // dp[i][j] => ending at index i, current len is j
        // dp[i][j] = dp[i-1][j-1] + dp[i-1][j-2] + ... , dp[i-1][j-c], c=cnt
        // just use prefix sum to improve

        // dp[i][j] = r=j-1, l=j-c, pre[r]-pre[l-1]
        
        // NOTE: we also can use fft but no need.

        int mod = 1e9+7;

        int n = word.size();
        vector<int> tmp;
        long total = 1;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && word[i] == word[j]) j++;
            total *= (j-i);
            total %= mod;
            tmp.push_back(j-i);
        }        

        // each group need at least choose 1
        if (tmp.size() >= k) return total;

        n = tmp.size();
        vector dp(n+1, vector(k, 0L));
        dp[0][0] = 1; // base

        for (int i = 0; i < n; ++i) {
            // prefix sum of prev
            vector<long> pre = dp[i];
            for (int j = 1; j < k; ++j)
                pre[j] = (pre[j] + pre[j-1]) % mod;

            for (int j = 0; j < k; ++j) {
                int l = j - tmp[i], r = j - 1;
                if (r < 0) continue;
                long left = l > 0 ? pre[l-1] : 0;
                long right = pre[r];
                dp[i+1][j] = (right - left + mod) % mod;
            }
        }

        // final ans
        for (int j = 0; j < k; ++j) {
            total -= dp[n][j];
            if (total < 0) total += mod;
        }
        return total;
    }
};
