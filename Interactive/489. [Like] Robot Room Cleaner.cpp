/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    set<pair<int, int>> vis;
    const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    void goBack(Robot& robot){
        // recover
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void dfs(Robot& robot, int x, int y, int d){
        robot.clean();
        vis.insert({x, y});
        
        for(int i = 0; i < 4; ++i){
            int nd = (d+i)%4;
            int nx = x+dir[nd][0], ny = y+dir[nd][1];
            if(!vis.count({nx, ny}) && robot.move()){
                dfs(robot, nx, ny, nd);
                goBack(robot);
            }
            robot.turnRight();
        }
        
    }
    
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
};
