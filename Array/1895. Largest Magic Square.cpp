class Solution {
public:
    
    void pp(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                cout << grid[i][j] << " \n"[j==n-1];
        cout << "\n";
    }
    
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        auto rowSum = grid; // each row prefix
        auto colSum = grid; // each col prefix
        auto dia1 = grid; // left to right down
        auto dia2 = grid; // right to left down
        
        for(int i = 0; i < m; ++i){
            for(int j = 1; j < n; ++j){
                rowSum[i][j] += rowSum[i][j-1];
            }
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 0; j < n; ++j){
                colSum[i][j] += colSum[i-1][j];
            }
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dia1[i][j] += dia1[i-1][j-1];
            }
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = n-2; j >= 0; --j){
                dia2[i][j] += dia2[i-1][j+1];
            }
        }
        
//         pp(rowSum);
//         pp(colSum);
//         pp(dia1);
//         pp(dia2);
        
        auto check = [&](int i, int j, int ri, int rj){
            int sum = -1;
            for(int k = j; k <= rj; ++k){
                int cs = colSum[ri][k] - (i > 0 ? colSum[i-1][k] : 0);
                if(sum == -1) sum = cs;
                else if(sum != cs) return false;
            }
            for(int k = i; k <= ri; ++k){
                int rs = rowSum[k][rj] - (j > 0 ? rowSum[k][j-1] : 0);
                if(sum == -1) sum = rs;
                else if(sum != rs) return false;
            }
            // cout << i << " " << j << " " << ri << " " << rj << " " << sum << "\n";
            
            int d1 = dia1[ri][rj] - (i > 0 && j > 0 ? dia1[i-1][j-1]: 0);
            if(d1 != sum) return false;
            int d2 = dia2[ri][j] - (i > 0 && rj+1 < n ? dia2[i-1][rj+1]: 0);
            if(d2 != sum) return false;
            return true;
        };
        
        int res = 1;
        for(int k = 2; k <= min(m, n); ++k){
            for(int i = 0; i+k-1 < m; ++i){
                for(int j = 0; j+k-1 < n; ++j){
                    int ri = i+k-1, rj = j+k-1;
                    if(check(i, j, ri, rj)) res = k;
                }
            }
        }
        
        return res;
    }
};
