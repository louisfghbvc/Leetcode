// Space O(NM).
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> tmp = board;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int c = 0;
                for(int x: {-1, 0, 1}){
                    for(int y: {-1, 0, 1}){
                        if(!x && !y) continue;
                        if(i+x < 0 || i+x >= m || j+y < 0 || j+y>= n || !tmp[i+x][j+y]) continue;
                        c++;
                    }
                }
                if(board[i][j]){
                    if(c < 2 || c >= 4) board[i][j] = 0;
                }
                else if(c == 3) board[i][j] = 1;
            }
        }
    }
};

// addtional Bit. Space O(1)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int c = 0;
                for(int x: {-1, 0, 1}){
                    for(int y: {-1, 0, 1}){
                        if(!x && !y) continue;
                        if(i+x < 0 || i+x >= m || j+y < 0 || j+y>= n || !(board[i+x][j+y]&1)) continue;
                        c++;
                    }
                }
                if(board[i][j]){
                    if(c == 2 || c == 3) board[i][j] |= 2;
                }
                else{
                    if(c == 3) board[i][j] |= 2;
                }
            }
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                board[i][j] >>= 1;
            }
        }
    }
};
