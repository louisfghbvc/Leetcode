// O(N + M). Bfs topology sort. and use dynamic programming

class Solution {
public:
    vector<vector<int>> g;
    typedef array<int, 26> A;
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        g = vector<vector<int>>(n);
        vector<int> ind(n);
        for(auto &e: edges){
            g[e[0]].push_back(e[1]);
            ind[e[1]]++;
        }
        
        vector<A> cnt(n, A{});
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(ind[i] == 0){
                q.push(i);
                cnt[i][colors[i] - 'a']++;
            }
        }
        
        int res = 0, seen = 0;
        while(q.size()){
            int u = q.front(); q.pop();
            int cur = *max_element(cnt[u].begin(), cnt[u].end());
            res = max(res, cur);
            seen++;
            for(int v: g[u]){
                // u update v
                for(int k = 0; k < 26; ++k)
                    cnt[v][k] = max(cnt[v][k], cnt[u][k] + (k == colors[v] - 'a'));
                if(--ind[v] == 0){
                    q.push(v);
                }
            }
        }
        
        // if has cycle, topo is smaller than n
        return seen < n ? -1 : res;
    }
};
