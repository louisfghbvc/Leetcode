// Calculate slope. O(N).
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dy = coordinates[1][1] - coordinates[0][1], dx = coordinates[1][0] - coordinates[0][0];
        for(int i = 2; i < coordinates.size(); ++i){
            int ty = coordinates[i][1] - coordinates[0][1], tx = coordinates[i][0] - coordinates[0][0];
            if((double)ty/tx != (double)dy/dx) return 0;
        }
        return 1;   
    }
};
