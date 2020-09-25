// Boring.
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int r = A.size(), c = A[0].size();
        vector<vector<int>> res(c, vector<int>(r));
        for(int j = 0; j < c; ++j)
            for(int i = 0; i < r; ++i)
                res[j][i] = A[i][j];
        return res;
    }
};
