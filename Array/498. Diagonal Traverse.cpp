// Boring..
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(!m) return res;
        int n = matrix[0].size();
        vector<int> lt[m+n];
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                lt[i+j].push_back(matrix[i][j]);
        
        for(int i = 0; i < m+n; ++i){
            if(i % 2 == 0) reverse(lt[i].begin(), lt[i].end());
            res.insert(res.end(), lt[i].begin(), lt[i].end());
        }
        
        return res;
    }
};
