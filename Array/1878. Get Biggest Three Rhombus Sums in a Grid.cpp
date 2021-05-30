// Prefix sum. 

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> res;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> pre1(n+1, vector<int>(m+1)); // left to right down
        vector<vector<int>> pre2(n+1, vector<int>(m+1));
        
        for(int i = 0; i < n; ++i){
            for(int ii = i, jj = 0; ii < n && jj < m; ++ii, ++jj){
                pre1[ii+1][jj+1] += pre1[ii][jj] + grid[ii][jj];
            }
        }        
        
        for(int j = 1; j < m; ++j){
            for(int ii = 0, jj = j; ii < n && jj < m; ++ii, ++jj){
                pre1[ii+1][jj+1] += pre1[ii][jj] + grid[ii][jj];
            }
        }
        
        for(int i = 0; i < n; ++i){
            for(int ii = i, jj = m-1; ii < n && jj >= 0; ++ii, --jj){
                pre2[ii+1][jj] += pre2[ii][jj+1] + grid[ii][jj];
            }
        }   
        
        for(int j = m-2; j >= 0; --j){
            for(int ii = 0, jj = j; ii < n && jj >= 0; ++ii, --jj){
                pre2[ii+1][jj] += pre2[ii][jj+1] + grid[ii][jj];
            }
        }
        
//         for(int i = 0; i < n; ++i){
//             for(int j = 0; j < m; ++j)
//                 cout << grid[i][j] << " \n"[j+1==m];
//         }
        
//         for(int i = 0; i <= n; ++i){
//             for(int j = 0; j <= m; ++j)
//                 cout << pre1[i][j] << " \n"[j==m];
//         }
        
//         for(int i = 0; i <= n; ++i){
//             for(int j = 0; j <= m; ++j)
//                 cout << pre2[i][j] << " \n"[j==m];
//         }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                res.insert(grid[i][j]);
                for(int len = 1; ; ++len){
                    int Ri = i + len, Rj = j + len;
                    int Di = i + 2*len, Dj = j;
                    int Li = i + len, Lj = j - len;
                    if(Ri >= n || Rj >= m || Di >= n || Li >= n || Lj < 0) break;
                    // cout << i << " " << j << "\n";
                    int RtoU = pre1[Ri+1][Rj+1] - pre1[i][j] - grid[i][j] - grid[Ri][Rj];
                    int DtoL = pre1[Di+1][Dj+1] - pre1[Li][Lj] - grid[Di][Dj] - grid[Li][Lj];
                    int LtoU = pre2[Li+1][Lj] - pre2[i][j+1];
                    int DtoR = pre2[Di+1][Dj] - pre2[Ri][Rj+1];
                    // cout << "RtoU " << RtoU << "\n";
                    // cout << "DtoL " << DtoL << "\n";
                    // cout << "LtoU " << LtoU << "\n";
                    // cout << "DtoR " << DtoR << "\n";
                    res.insert(RtoU + DtoL + LtoU + DtoR);
                }
            }
        }
        
        vector<int> tmp(res.begin(), res.end());
        reverse(tmp.begin(), tmp.end());
        if(tmp.size() > 3) tmp.resize(3);
        return tmp;
    }
};
