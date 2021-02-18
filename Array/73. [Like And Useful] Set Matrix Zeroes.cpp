// space O(M+N).
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return;
        int m = matrix[0].size();
        set<int> row, col;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!matrix[i][j]){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(int r: row){
            for(int j = 0; j < m; ++j)
                matrix[r][j] = 0;
        }
        
        for(int c: col){
            for(int i = 0; i < n; ++i)
                matrix[i][c] = 0;
        }
    }
};

// O(1) space. push flag to left most and top most. column 0 need to store. cuz overlap.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return;
        int m = matrix[0].size();
        
        bool col0 = false;
        for(int i = 0; i < n; ++i){
            if(!matrix[i][0]) col0 = true;
            for(int j = 1; j < m; ++j){
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = n-1; i >= 0; --i){
            for(int j = m-1; j >= 1; --j){
                if(!matrix[i][0] || !matrix[0][j]) 
                    matrix[i][j] = 0;
            }
            if(col0) matrix[i][0] = 0;
        }
    }
};
