// Leetcode 84, 85 tweak. hard?
// O(MNlogN). record each columns continous 1. and greedy sort.
// enum all row.

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int dwn[m+2][n+2];
        
        memset(dwn, 0, sizeof dwn);
        for (int i = m - 1; i >= 0; i--){
            for (int j = 0; j < n; ++j){
                if (mat[i][j] == 0)
                    dwn[i][j] = 0;
                else dwn[i][j] = dwn[i + 1][j] + 1;
            }
        }
        
        vector<int> b(n, 0);
        int mx = 0;
  
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j) 
                b[j] = dwn[i][j]; 

            sort(b.begin(), b.end());
            for (int i = 0; i < n; ++i)
                mx = max(mx, b[i] * (n - i));
        }
        
        return mx;
    }
};
