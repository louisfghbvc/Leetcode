// Enumerate all position, O(MN?). since only put in bound '#'.
class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int l = word.size();
        
        auto check = [&](int x, int y, int dx, int dy){
            int i = 0;
            while(i < l){
                if(x < 0 || x > m || y < 0 || y >= n) break;
                if(board[x][y] != word[i] && board[x][y] != ' ') return false;
                x += dx;
                y += dy;
                i += 1;
            }
            return i == l;
        };
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                // put going up
                bool can_put = (i+1 == m || board[i+1][j] == '#') && (i == l - 1 || (i-l>=0 && board[i-l][j] == '#')); 
                if(can_put && check(i, j, -1, 0)) return true;
                
                // put down
                can_put = (i == 0 || board[i-1][j] == '#') && (i+l == m || (i+l<m && board[i+l][j] == '#')); 
                if(can_put && check(i, j, 1, 0)) return true;
                
                // put left
                can_put = (j+1 == n || board[i][j+1] == '#') && (j == l - 1 || (j-l>=0 && board[i][j-l] == '#')); 
                if(can_put && check(i, j, 0, -1)) return true;
                
                // put right
                can_put = (j == 0 || board[i][j-1] == '#') && (j+l == n || (j+l<n && board[i][j+l] == '#')); 
                if(can_put && check(i, j, 0, 1)) return true;
            }
        }
        
        return false;
    }
};


// O(MN), Normalize to left to right, tricky
// only start with first, or '#'
class Solution {
public:
    
    bool helper(vector<vector<char>> &grid, const string& word){
        int m = grid.size(), n = grid[0].size();
        int l = word.size();
        for(int i = 0; i < m; ++i){
            int k = 0;
            bool ok = true;
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '#'){
                    if(k == l && ok) return true;
                    ok = true; // reset
                    k = 0;
                }
                else if(grid[i][j] == ' ') k++;
                else{
                    if(k == l || (k<l && grid[i][j] != word[k])) ok = false;
                    k++;
                }
            }
            if(k == l && ok) return true;
        }
        return false;
    }
    
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        string rev(word.rbegin(), word.rend());
        
        int m = board.size(), n = board[0].size();
        vector<vector<char>> tran_board(n, vector<char>(m));
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; j++)
                tran_board[j][i] = board[i][j];
        
        return helper(board, word) || helper(board, rev) || helper(tran_board, word) || helper(tran_board, rev);
    }
};
