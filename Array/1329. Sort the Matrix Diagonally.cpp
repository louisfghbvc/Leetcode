//36ms 10.5MB
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int k = 0; k < m; ++k){
            for(int i = 0; i + 1< m; ++i){
                for(int j = 0; j + 1< n; ++j){
                    if(mat[i][j] > mat[i + 1][j + 1])
                        swap(mat[i][j], mat[i + 1][j + 1]);
                }
            }
        }
        
        return mat;
    }
};
