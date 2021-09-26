// Enumerate all position, O(MN?)

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
