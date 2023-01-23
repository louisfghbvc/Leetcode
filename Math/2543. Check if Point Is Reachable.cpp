class Solution {
public:
    
    map<pair<int, int>, bool> dp;
    bool isReachable(int targetX, int targetY) {
        if (targetX == 1 || targetY == 1) return true;
        if (targetX < 1 || targetY < 1) return false;
        
        // goal: is reachale
        // idea: dp, op1, op2 use mod
        // (x, y - x)
        // (x - y, y)
        // (2 * x, y)
        // (x, 2 * y)
        
        // (tx, ty)

        if (dp.count({targetX, targetY})) return dp[{targetX, targetY}];
        bool &res = dp[{targetX, targetY}];
        res = false;
        
        if (targetX % 2 == 0) {
            res = res | isReachable(targetX / 2, targetY);
        }
        if (targetY % 2 == 0) {
            res = res | isReachable(targetX, targetY / 2);
        }
        if (targetX >= targetY) {
            res = res | isReachable(targetX % targetY, targetY);
        }
        if (targetX <= targetY) {
            res = res | isReachable(targetX, targetY % targetX);
        }
        
        return res;
    }
};
