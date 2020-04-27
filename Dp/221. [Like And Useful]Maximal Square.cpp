// better brute force O(N^3)
// 2D Prefix sum
// 140ms 9MB
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pre(n+1, vector<int>(m+1, 0) );
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + (matrix[i][j] == '1');
            }
        }
        /*
        for(auto row: pre){
            for(auto col : row){
                cout << col << " ";
            }
            cout << endl;
        }*/
        int side = min(m, n), mx = 0;
        for(int l = 0; l < side; ++l){
            for(int i = 0; i+l < n; ++i){
                for(int j = 0; j+l < m; ++j){
                    int v = pre[i+l+1][j+l+1] + pre[i][j] - pre[i+l+1][j] - pre[i][j+l+1];
                    if(v != (l+1)*(l+1)) continue;
                    mx = max(mx, v);
                }
            }
        }
        return mx;
    }
};

// Better algorithm. Dp O(N^2)
// Think. if arr[i][j] == 1: dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1
// Why ? because square just need to check 3 adj, then append. dp means max side it can have.
// Not Space Optimal.
// 8ms 8.8MB
static int p = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 1;
}();
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        int side = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                // append from adj
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                    side = max(side, dp[i][j]);
                }
            }
        }
        
        return side*side;
    }
};
