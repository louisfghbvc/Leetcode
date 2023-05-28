class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // goal: min extra char
        // idea: 
        // dict -> build a trie (no need)
        // brute force, start from each
        // dp[i]: minimum erase number starting from index i -> skip
        
        // idea2: look as segment, start from each number -> maximum length of non-overlapping
        // dp to do segs select
        
        
        int n = s.size();
        
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<pair<int, int>> segs;
        for (int i = 0; i < n; ++i) {
            string t;
            for (int j = i; j < n; ++j) {
                t += s[j];
                if (dict.count(t))
                    segs.emplace_back(i, j);
            }
        }
            
        // 1, 4
        //   2   8
        // 1        10
        //     3         15
        sort(segs.begin(), segs.end(), [&](auto &a, auto &b) {
            return a.second < b.second;    
        });   
        
        int m = segs.size();
        vector dp(m, 0);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int len = segs[i].second - segs[i].first+1;
            dp[i] = len;
            for (int j = 0; j < i; ++j) {
                if (segs[j].second < segs[i].first) {
                    dp[i] = max(dp[i], len + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return n - ans;
    }
};


// Way2 - TC: O(n^2)
