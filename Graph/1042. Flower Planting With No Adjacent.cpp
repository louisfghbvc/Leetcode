// O(N).
// So the key idea is check each adj color. and choose the not colored.
// because must be one answer so just color each node from 0 ~ N

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> g[N];
        vector<int> res(N);
        for(auto &e: paths){
            g[e[0]-1].push_back(e[1]-1);
            g[e[1]-1].push_back(e[0]-1);
        }
        for(int u = 0; u < N; ++u){
            bool cc[5] = {};
            for(auto &v: g[u]){
                cc[res[v]] = 1;
            }
            int i;
            for(i = 1; i <= 4; ++i) if(!cc[i]) break;
            res[u] = i;
        }
        return res;
    }
};
