// 8 dir check.
class Solution {
public:
    
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int n = board.size();
        int m = board[0].size();
        
        board[rMove][cMove] = color;
        
        
        for(int dx : {-1, 0, 1}){
            for(int dy : {-1, 0, 1}){
                if(!dx && !dy) continue;
                
                int i = rMove, j = cMove;
                auto check = [&](){
                    int ni = i+dx, nj = j+dy;
                    bool hasOpp = 0;
                    while(ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] != '.' && board[ni][nj] != color){
                        hasOpp = 1;
                        ni = ni+dx, nj = nj+dy;
                    }
                    if(hasOpp && ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] == color) return true;
                    return false;
                };                
                if(check()) return true;
            }
        }
        
        return false;
    }
};
