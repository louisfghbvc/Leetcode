// Tricky... Now I understand.
// So just sort small from big.
// and merge row, col with equal value.
// dynamic UF.

class Solution {
public:
    int p[1005];
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        
        map<int, vector<int>> mp;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                mp[matrix[i][j]].push_back(i*n+j);
            }
        }
        
        vector<int> rank(m+n);
        for(auto &[_, idx] : mp){
            memset(p, -1, sizeof p);
            
            for(int id: idx){ // merge row and col
                int i = id/n, j = id%n;
                int r1 = find(i), r2 = find(m + j);
                if(r1 != r2){
                    p[r2] = r1;
                    rank[r1] = max(rank[r1], rank[r2]);
                } 
            }
            
            vector<int> rank2 = rank;
            for(int id: idx){ // assign ans. only use once.
                int i = id/n, j = id%n;
                int r = find(i);
                ans[i][j] = rank[r] + 1;
                rank2[i] = rank[r] + 1;
                rank2[j + m] = rank[r] + 1;
            }
            rank = rank2;
        }
        
        return ans;
    }
};
