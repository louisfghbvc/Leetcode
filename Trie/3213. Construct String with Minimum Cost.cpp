class Solution {
public:
    
    struct trieNode {
        trieNode* next[26]{};
        int val = -1;
    } *root;
    
    void add(string &s, int val) {
        trieNode* cur = root;
        for (char c: s) {
            if (!cur->next[c-'a']) cur->next[c-'a'] = new trieNode();
            cur = cur->next[c-'a'];
        }
        if (cur->val == -1 || cur->val > val)
            cur->val = val;
    }
    
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        // goal: find the minimum cost to make empty s to target
        
        // idea: dp
        // dp[i] : minimum cost starting from index i
        
        // dfs(i) -> cost[?] + dfs(j), target[i:j] is in the word
        // instead using mp, use trie
        
        int n = target.size();
        vector dp(n, -1);
        
        // unordered_map<string, int> mp;
        root = new trieNode();
        for (int i = 0; i < words.size(); ++i) {
            add(words[i], costs[i]);
        }
        
        auto dfs = [&](auto &self, int i) -> int {
            if (i >= n) return 0;
            
            int &res = dp[i];
            if (res != -1) return res;
            
            res = 1e9;
            trieNode* tmp = root;
            for (int j = i; j < n && tmp; ++j) {
                tmp = tmp->next[target[j]-'a'];
                if (tmp && tmp->val != -1) {
                    res = min(res, tmp->val + self(self, j+1));
                }
            }
            return res;
        };
        
        int res = dfs(dfs, 0);
        if (res == 1e9) res = -1;
        
        return res;
    }
};
