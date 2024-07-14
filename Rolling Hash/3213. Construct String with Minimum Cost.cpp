// Approach1. Dp with hash

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        // goal: find the minimum cost to construct the target
        // idea:
        // words, if we group by length?
        // how many distinct length?? O(sqrt(5*10^4))
        // Can we enumerate each length in each index??
        // need a sturcture => len: {(word, cost) ....}
        // first, we need to bulld the word<->cost relation
        // second, build the length structure
        // we can using rolling hash to speed up the compare
        // then, using dp
        
        int BASE = 37;

        // build the map
        unordered_map<int, unordered_map<int, int>> mp; // len -> hash -> cost
        for (int i = 0; i < words.size(); ++i) {
            unsigned h = 0;
            for (char c: words[i])
                h = h*BASE+c-'a';
            int len = words[i].size();
            if (mp[len].count(h))
                mp[len][h] = min(mp[len][h], costs[i]);
            else
                mp[len][h] = costs[i];
        }

        // hash
        // a   b   c d ...
        // x^0
        // x^1+x^0
        int n = target.size();
        vector<unsigned> pow(n+1, 1), pre(n+1);
        for (int i = 1; i <= n; ++i)
            pow[i] = pow[i-1] * BASE;
        for (int i = 0; i < n; ++i) {
            pre[i] = target[i]-'a';
            if (i)
                pre[i] += pre[i-1] * BASE;
        }
        auto query = [&](int l, int r) {
            if (l == 0) return pre[r];
            return pre[r] - pre[l-1] * pow[r-l+1];
        };

        // doing dp, top down dp -> TLE
        vector<int> dp(n+1, 1e9);
        dp[n] = 0;
        for (int i = n-1; i >= 0; --i) {
            int res = 1e9;
            for (auto &[len, curMp]: mp) {
                if (i + len > n) continue;
                auto h = query(i, i+len-1);
                if (curMp.count(h))
                    res = min(res, curMp[h] + dp[i+len]); 
            }
            dp[i] = res;
        }

        int res = dp[0];
        if (res == 1e9) res = -1;
        return res;
    }
};

// Trie -> TLE, TC: O(N^2)
