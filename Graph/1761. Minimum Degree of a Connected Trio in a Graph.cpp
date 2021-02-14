// O(N^3). Enum all case. use adjacent matrix to record edge.

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int res = 1e9;
        vector<int> in(n+1);
        vector<vector<bool>> vis(n+1, vector<bool>(n+1));
        for(auto &e: edges){
            vis[e[0]][e[1]] = vis[e[1]][e[0]] = 1;
            in[e[0]]++;
            in[e[1]]++;
        }

        bool ct = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i+1; j <= n; ++j){
                for(int k = j+1; k <= n; ++k){
                    if(vis[i][j] && vis[j][k] && vis[i][k]){
                        res = min(in[i] + in[j] + in[k] - 6, res);
                        ct = 1;
                    }
                }
            }
        }
        
        if(!ct) return -1;
        return res;
    }
};
