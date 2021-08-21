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


// use extra space to do O(1) check
class Solution {
public:
    bool row[9][10], col[9][10], sub[9][10];
    
    int get(int i, int j){
        return (i/3) * 3 + j/3; 
    }
    
    bool check(vector<vector<char>>& board, int i, int j){
        if(row[i][board[i][j] - '0'] ||
           col[j][board[i][j] - '0'] || 
           sub[get(i, j)][board[i][j] - '0']) return false;
        return true;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j){
        if(i == 9) return true;
        if(j == 9) return dfs(board, i+1, 0);
        if(board[i][j] != '.') return dfs(board, i, j+1);
            
        for(int d = 1; d <= 9; ++d){
            board[i][j] = '0'+d;
            if(check(board, i, j)){
                row[i][d] = 1;
                col[j][d] = 1;
                sub[get(i, j)][d] = 1;
                if(dfs(board, i, j+1)) return true;
                row[i][d] = 0;
                col[j][d] = 0;
                sub[get(i, j)][d] = 0;
            }
            board[i][j] = '.';
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                row[i][board[i][j] - '0'] = 1;
                col[j][board[i][j] - '0'] = 1;
                sub[get(i, j)][board[i][j] - '0'] = 1;
            }
        }
        dfs(board, 0, 0);
    }
};
