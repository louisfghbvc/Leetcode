class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // goal: given the commands, have turn left/turn right
        // when enter into obstacles -> we need to skip to next index
        // we need to find the farest distance
        // idea:
        // simulate it, obstacles using hashmap to record

        set<pair<int, int>> st;
        for (auto &v: obstacles)
            st.emplace(v[0], v[1]);

        int x=0,y=0;
        int curD=0; // 0 north
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        int ans = 0;
        for (int k: commands) {
            if (k == -1) {
                curD = (curD+1) % 4;
            }
            else if (k == -2) {
                curD = (curD-1+4) % 4;
            }
            else {
                while (k--) {
                    x += dir[curD][0];
                    y += dir[curD][1];
                    if (st.count({x, y})) {
                        x -= dir[curD][0];
                        y -= dir[curD][1];
                        break; // meets obstacle
                    }
                }
                ans = max(ans, x*x+y*y);
            }
        }

        return ans;
    }
};
