// do backward
// tx > ty -> tx-ty, since ty-tx < 0, never happen
// and use mod to fast
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // goal: if can from sx->tx, sy->ty

        // (x+y, y) -> (x-y, y)
        // (x, x+y) -> (x, y-x)

        while (sx < tx && sy < ty) {
            if (tx < ty) ty %= tx;
            else tx %= ty;
        }

        return sx == tx && sy <= ty && (ty-sy)%tx == 0 ||  
               sy == ty && sx <= tx && (tx-sx)%ty == 0;
    }
};
