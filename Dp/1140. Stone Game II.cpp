class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        // goal: find out the maximum piles A can get
        // each player: can choose first X piles
        // then set M into max(m, x)

        // idea:
        // dp
        // dfs(i, m, bool isA): starting from index i, the maximum first player can get
        // dfs(i, m): max of {dfs(j, max(m, j-i))} where j > i and j-i <= 2*m 

        int n = piles.size();
        vector dp(n+1, vector(n+1, vector(2, -1)));
        auto dfs =[&](auto& self, int i, int m=1, bool isAlice=true) -> int {
            if (i >= n) return 0;

            int &res = dp[i][m][isAlice];
            if (res != -1) return res;

            if (isAlice) {
                res = 0;
                int sum = 0;
                for (int j = i; j < n && j-i+1 <= 2*m; ++j) {
                    sum += piles[j];
                    res = max(res, sum + self(self, j+1, min(n, max(m, j-i+1)), !isAlice));
                }
            }
            else {
                res = 1e9;
                for (int j = i; j < n && j-i+1 <= 2*m; ++j) {
                    res = min(res, self(self, j+1, min(n, max(m, j-i+1)), !isAlice));
                }
            }

            return res;
        };

        return dfs(dfs, 0);
    }
};

// Approach 2
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        // goal: find out the maximum piles A can get
        // each player: can choose first X piles
        // then set M into max(m, x)

        // idea:
        // dp
        // dfs(i, m): starting from index i, the maximum player can get
        // dfs(i, m): max of {dfs(j, max(m, j-i))} where j > i and j-i <= 2*m 
        // we can convert to 2D
        // compute the suffix sum then we know other player can get
        // suf[i] - dfs(i+x, max(x,m)) ...

        int n = piles.size();
        vector<int> suf = piles;
        for (int i = n-2; i >= 0; --i)
            suf[i] += suf[i+1]; 

        vector dp(n+1, vector(n+1, -1));
        auto dfs =[&](auto& self, int i, int m=1) -> int {
            if (i >= n) return 0;

            int &res = dp[i][m];
            if (res != -1) return res;

            res = 0;
            for (int x = 1; x <= 2*m && i+x <= n; ++x) {
                res = max(res, suf[i] - self(self, i+x, max(x,m)));
            }

            return res;
        };

        return dfs(dfs, 0);
    }
};
