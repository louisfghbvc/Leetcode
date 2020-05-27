// DFS, Bicolor problem. use lambda.
// if colored, check is same from that parent color.
// if not colored, color from parent color.
// all cur node, try to color nxt node.
// O(N+E).

class Solution {
public:
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> g[N+1];
        vector<bool> cc(N+1);
        for(const auto&e : dislikes){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        function<bool(int, int)> dfs = [&](int u, int c){
            if(cc[u]) return cc[u] == c; 
            cc[u] = c;
            for(const auto&v: g[u]){
                if(!dfs(v, c^1)) return false;
            }
            return true;
        };
        
        for(int i = 1; i <= N; ++i){
            if(!cc[i] && !dfs(i, 0)) return 0;
        }
        return 1;
    }
};
