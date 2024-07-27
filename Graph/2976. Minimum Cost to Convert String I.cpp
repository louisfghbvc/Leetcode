class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // goal: find the minimum cost from source to target
        // original -> change it cost z
        // x -> y cost z
        // idea:
        // convert change to graph, ori -> chan has cost[i]
        // we can compute all pair shortest path
        // dp[x][y] : min cost make x to y

        vector dp(26, vector(26, -1));
        for (int i = 0; i < cost.size(); ++i) {
            char u = original[i]-'a', v = changed[i]-'a';
            int w = cost[i];
            if (dp[u][v] == -1 || dp[u][v] > w)
                dp[u][v] = w;
        }
        for (int i = 0; i < 26; ++i)
            dp[i][i] = 0;

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dp[i][k] != -1 && dp[k][j] != -1) {
                        int &val = dp[i][j];
                        if (val == -1 || val > dp[i][k]+dp[k][j])
                            val = dp[i][k]+dp[k][j];
                    }
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < source.size(); ++i) {
            char u = source[i]-'a', v = target[i]-'a';
            if (dp[u][v] != -1)
                ans += dp[u][v];
            else // impossible
                return -1;
        }
        return ans;
    }
};
