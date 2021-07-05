// Simulation
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r * c != mat.size() * mat[0].size()) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        
        int x = 0, y = 0;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                res[i][j] = mat[x][y];
                ++y;
                if(y == mat[0].size()) x++, y = 0;
            }
        }
        
        return res;
    }
};
