// Simple O(N^3). Can optimal to O(N^2).

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        int n = mat.size(), m = mat[0].size();
        auto check = [&](int r, int c){
            for(int i = 0; i < n; ++i) if(i != r && mat[i][c]) return 0;
            for(int i = 0; i < m; ++i) if(i != c && mat[r][i]) return 0;
            return 1;
        };
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] && check(i, j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
