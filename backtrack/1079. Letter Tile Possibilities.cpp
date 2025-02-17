class Solution {
public:
    int sum = 0;
    void dfs(vector<int> &arr){
        for(int i = 0; i < 26; ++i){
            if(arr[i] == 0) continue;
            sum++;
            --arr[i];
            dfs(arr);
            ++arr[i];
        }  
    }
    int numTilePossibilities(string tiles) {
        vector<int> count(26, 0);
        for(auto c : tiles)
            count[c - 'A']++;
        dfs(count);
        return sum;
    }
};


// way2 - DP
// think fix the length and fix the letter
class Solution {
public:
    int numTilePossibilities(string tiles) {
        // goal: find the all possible string that can make by the tiles
        // idea:
        // consider in a single length
        // AABBC => we only consider the length is 5
        // fix A
        // _ A _ _ A => 5 positions choose 2
        // BBC => choose the length 3
        // what is the base case?

        // each letter we only record the fre
        // for each letter => we can enumerate only choose number 1,2...

        int n = tiles.size();

        // preprocessing
        vector C(n+1, vector(n+1, 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                C[i][j] = C[i-1][j] + C[i-1][j-1];
            }
        }

        vector<int> cnt(26);
        for (char c: tiles)
            cnt[c-'A']++;

        vector dp(27, vector(n+1, -1));
        auto dfs = [&](auto& self, int i, int len) -> int {
            // base case
            if (i >= 26) return len == 0;

            int& res = dp[i][len];
            if (res != -1) return res;

            res = 0;
            // skip, use letter i
            for (int c = 0; c <= cnt[i] && len-c >= 0; ++c) {
                res = res + C[len][c] * self(self, i+1, len-c);
            }

            return res;
        };  

        // enumerate the length from 1-n
        int ans = 0;
        for (int len = 1; len <= n; ++len)
            ans += dfs(dfs, 0, len);
        return ans;
    }
};
