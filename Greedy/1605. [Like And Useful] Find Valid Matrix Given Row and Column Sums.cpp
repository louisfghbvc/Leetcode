// Awesome solution.
// take smaller from row or col. and update row and col.
// we are greedily put as much as possible
// O(MN)

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r = rowSum.size(), c = colSum.size();
        vector<vector<int>> res(r, vector<int>(c));
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
        
        return res;
    }
};
