// Can one pass. but lazy.
// O(N).

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        int n = mat.size();
        for(int i = 0; i < n; ++i){
            res += mat[i][i];
        }
        for(int i = n-1, j = 0; i >= 0; --i, ++j){
            res += mat[i][j];
        }
        if(n & 1) res -= mat[n/2][n/2];
        return res;
    }
};
