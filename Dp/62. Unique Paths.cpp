// O(MN). Optimal space. 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cnt(n, 1);
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                cnt[j] += cnt[j-1];
            }
        }
        
        return cnt.back();
    }
};

// O(MN), Easy to understand
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cnt(m+1, vector<int>(n+1, 0));
        cnt[0][0] = 1;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                cnt[i][j+1] += cnt[i][j];
                cnt[i+1][j] += cnt[i][j];
            }
        }
        
        return cnt[m-1][n-1];
    }
};
