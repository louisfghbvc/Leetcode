// O(N^3). Floyd Warshall. tweak with bool.
// 340ms.
// query O(1).
class Solution {
public:
    bool w[105][105];
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        memset(w, 0, sizeof w);
        vector<bool> ans;
        for(const auto&e: prerequisites){
            w[e[0]][e[1]] = 1;
        }
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    w[i][j] |= w[i][k] && w[k][j]; 
                }
            }
        }
        for(const auto& q:queries){
            int s = q[0], t = q[1];
            ans.push_back(w[s][t]);
        }
        return ans;
    }
};
