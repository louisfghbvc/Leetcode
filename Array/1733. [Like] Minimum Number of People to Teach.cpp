// O(NM). just enum all language, and use bitset check intersect.

class Solution {
public:
    #define bt bitset<505>
    int minimumTeachings(int n, vector<vector<int>>& lg, vector<vector<int>>& friendships) {
        int m = lg.size();
        vector<bt> arr(m);
        for(int i = 0; i < m; ++i){
            for(auto &x: lg[i])
                arr[i][x] = 1;
        }
        
        int res = 1e9;
        for(int l = 1; l <= n; ++l){
            int teach = 0;
            vector<bool> used(m);
            for(auto&e: friendships){
                int u = e[0]-1, v = e[1]-1;
                if((arr[u] & arr[v]).count()) continue;
                
                if(!arr[u][l] && !used[u]){
                    used[u] = 1;
                    teach++;
                }
                if(!arr[v][l] && !used[v]){
                    used[v] = 1;
                    teach++;
                }
            }
            res = min(res, teach);
        }
        
        return res;
    }
};
