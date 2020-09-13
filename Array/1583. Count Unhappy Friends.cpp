// O(N^2). Build preprocess table to record the rank and edge.

class Solution {
public:
    int rank[505][505];
    int unhappyFriends(int n, vector<vector<int>>& prefer, vector<vector<int>>& pairs) {
        int ps = pairs.size(), res = 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < prefer[i].size(); ++j)
                rank[i][prefer[i][j]] = j;
        }
        
        vector<int> edge(n);
        for(auto &e: pairs){
            edge[e[0]] = e[1];
            edge[e[1]] = e[0];
        }
        
        for(int x = 0; x < n; ++x){
            for(int u = 0; u < n; ++u){
                if(u != x && edge[x] != u){
                    int y = edge[x], v = edge[u];
                    if(rank[x][u] < rank[x][y] && rank[u][x] < rank[u][v]){
                        res++;
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};
