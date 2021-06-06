class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size(), m = mat[0].size();
        for(int k = 0; k < 4; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = i+1; j < m; ++j){
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for(int i = 0; i < n; ++i)
                reverse(mat[i].begin(), mat[i].end());
            bool ok = 1;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                    ok = ok && (mat[i][j] == target[i][j]);
            if(ok) return true;
            
        }
        return false;
    }
};
