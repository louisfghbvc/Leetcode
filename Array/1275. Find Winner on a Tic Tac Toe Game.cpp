class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> g(3, vector<int>(3));
        auto check = [&](int val){
            // row
            for(int i = 0; i < 3; ++i)
                if(g[i][0] == val && g[i][1] == val && g[i][2] == val) return true;
            // col
            for(int j = 0; j < 3; ++j)
                if(g[0][j] == val && g[1][j] == val && g[2][j] == val) return true;
            if(g[0][0] == val && g[1][1] == val && g[2][2] == val) return true;
            if(g[0][2] == val && g[1][1] == val && g[2][0] == val) return true;
            return false;
        };
        
        for(int i = 0; i < moves.size(); ++i){
            if(i % 2){ // B
                g[moves[i][0]][moves[i][1]] = 2;
                if(check(2)) return "B";
            }
            else{ // A
                g[moves[i][0]][moves[i][1]] = 1;
                if(check(1)) return "A";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};

// use extra array. Arows, Acols.
