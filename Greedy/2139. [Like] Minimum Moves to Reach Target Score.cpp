// do it reverse.
// O(logN), since we want the msb use maxDouble

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        int moves = 0;
        while(target > 1){
            if(maxDoubles-- > 0){
                moves += target % 2 + 1;
                target >>= 1;
            }
            else break;
        }
        
        return moves + (target - 1);
    }
};
