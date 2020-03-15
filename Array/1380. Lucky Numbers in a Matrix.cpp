//28ms 9.4MB, O(M * (N + M))
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; ++i){
            int mn = 1e9, id = 0;
            bool ok = true;
            for(int j = 0; j < n; ++j){
                if(mn > matrix[i][j]){
                    mn = matrix[i][j];
                    id = j;
                }
            }
            for(int k = 0; k < m; ++k){
                if(k == i) continue;
                if(mn < matrix[k][id]){
                    ok = false;
                    break;
                }
            }
            if(ok)
                ans.push_back(mn);
        }
        
        return ans;
    }
};
