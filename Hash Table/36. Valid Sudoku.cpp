// O(81). use array to record
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // enumerate row
        // enumerate col
        // enumerate subgrid
        bool row[9][10] = {};
        bool col[9][10] = {}; 
        bool subgrid[9][10] = {};
        
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                char c = board[i][j];
                if(c != '.'){
                    int ind = (i/3) * 3 + j/3;
                    if(row[i][c-'0'] || col[j][c-'0'] || subgrid[ind][c-'0']) return false;
                    row[i][c-'0'] = col[j][c-'0'] = subgrid[ind][c-'0'] = 1;
                }
            }
        }
        
        return true;
    }
};
