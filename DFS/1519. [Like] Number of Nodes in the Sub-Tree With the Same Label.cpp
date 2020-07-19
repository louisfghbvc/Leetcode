// O(26*N). dfs, top-down

class Solution {
public:
    vector<int> g[100005];
    string lb;
    vector<int> res;
    int fre[100005][26];
    void dfs(int u, int p){
        char c = lb[u];
        for(auto &v: g[u]){
            if(v == p) continue;
            dfs(v, u);
            for(int i = 0; i < 26; ++i)
                fre[u][i] += fre[v][i];
        }
        res[u] = ++fre[u][c-'a'];
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(int i = 0; i < n; ++i) g[i].clear();
        memset(fre, 0 ,sizeof fre);
        lb = labels;
        for(auto &e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        res.resize(n);
        dfs(0, -1);
        return res;
    }
};

// Reverse More fast. O(N). TW William Lin
// and space more optimal.
// lc before enter dfs cnt.
// after dfs use cnt - lc, can get true subtree cnt

class Solution {
public:
    vector<vector<int>> g;
    int c[26] = {};
    string lb;
    vector<int> res;
    
    void dfs(int u = 0, int p = -1){
        int lc = c[lb[u]-'a']++;
        for(auto &v: g[u]){
            if(v == p) continue;
            dfs(v, u);
        }
        res[u] = c[lb[u]-'a'] - lc;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        g = vector<vector<int>>(n);
        lb = labels;
        for(auto&e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        res = vector<int>(n);
        dfs();
        return res;
    }
};
