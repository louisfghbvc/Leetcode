// Simulate that game. trick is i - i%3. check 9 3x3 sub-boxes
// put a number and check.
class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, char val){
        int row = i - i%3, col = j - j%3;
        for(int x = 0; x < 9; ++x) if(board[x][j] == val) return 0;
        for(int y = 0; y < 9; ++y) if(board[i][y] == val) return 0;
        for(int x = 0; x < 3; ++x)
            for(int y = 0; y < 3; ++y)
                if(board[x+row][y+col] == val) return 0;
        return 1;
    }
    bool solveSudoku(vector<vector<char>>& board, int i, int j){
        if(i == 9) return 1;
        if(j == 9) return solveSudoku(board, i+1, 0);
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);
        for(char c = '1'; c <= '9'; ++c){
            if(check(board, i, j, c)){
                board[i][j] = c;
                if(solveSudoku(board, i, j+1)) return 1;
                board[i][j] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
};
