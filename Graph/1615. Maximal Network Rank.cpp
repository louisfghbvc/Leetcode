// Simple count degree of node.
// and Enum. Wa 2 times. so sad. இ௰இ
// O(N^2).

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int res = 0;
        int deg[105] = {};
        set<pair<int, int>> eg;
        for(auto &e: roads){
            deg[e[0]]++;
            deg[e[1]]++;
            eg.insert({e[0], e[1]});
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int f = 0;
                if(eg.count({i, j}) || eg.count({j, i})) f = 1;
                res = max(deg[i] + deg[j] - f, res);
            }
        }
        
        return res;
    }
};
