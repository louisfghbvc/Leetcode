// O(N^2 + ?). ? is path numbers.
class Solution {
public:
    
    int dif(string &a, string &b){
        assert(a.size() == b.size());
        int cnt = 0;
        for(int i = 0; i < a.size(); ++i){
            cnt += a[i] != b[i];
        }
        return cnt;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        // check endWord exist
        int eI = -1;
        for(int i = 0; i < n; ++i){
            if(wordList[i] == endWord){
                eI = i;
                break;
            }
        }
        if(eI < 0) return {};
        
        wordList.push_back(beginWord);
        vector<vector<int>> g(n+1);
        for(int i = 0; i < n+1; ++i){
            for(int j = i+1; j < n+1; ++j){
                if(dif(wordList[i], wordList[j]) == 1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        vector<vector<string>> res;
        int sI = n;
        // do bfs.
        queue<pair<int, vector<string>>> q; // index, path
        
        q.push({sI, {wordList[sI]}});
        vector<int> dp(n+1, 1e9);
        dp[sI] = 0;
        while(q.size()){
            auto [u, p] = q.front(); q.pop();
            if(u == eI){
                res.push_back(p);
                continue;
            }
            for(int v: g[u]){
                if(dp[v] >= dp[u] + 1){
                    dp[v] = dp[u]+1;
                    p.push_back(wordList[v]);
                    q.push({v, p});
                    p.pop_back();
                }
            }
        }
        
        return res;
    }
};

// O(N * K + ?). we also can build graph use bfs. and then backtracking. so that memory can reduce.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dp; // dp[string] means shortest path to this
        for(auto &s: wordList) dp[s] = 1e9;
        vector<vector<string>> res;
        
        if(!dp.count(endWord)) return res;
        
        queue<pair<string, vector<string>>> q; // node, path
        q.push({beginWord, {beginWord}});
        
        dp[beginWord] = 0;
        
        // do bfs
        while(q.size()){
            auto [u, path] = q.front(); q.pop();
            if(u == endWord){
                res.push_back(path);
                continue;
            }
            for(int i = 0; i < u.size(); ++i){
                char old = u[i];
                for(char c = 'a'; c <= 'z'; ++c) if(c != u[i]){
                    u[i] = c;
                    if(!dp.count(u)) continue;
                    if(dp[u] < path.size()) continue;
                    dp[u] = path.size();
                    path.push_back(u);
                    q.push({u, path});
                    path.pop_back();
                }
                u[i] = old;
            }
        }
        
        return res;
    }
};
