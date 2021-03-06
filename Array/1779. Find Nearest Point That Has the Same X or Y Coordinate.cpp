// Simple array.
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1;
        int dis = 1e9;
        for(int i = 0; i < points.size(); ++i){
            if(points[i][0] == x || points[i][1] == y){
                if(res == -1 || dis > abs(points[i][0] - x) + abs(points[i][1] - y)){
                    dis = abs(points[i][0] - x) + abs(points[i][1] - y);
                    res = i;
                }
            }
        }
        return res;
    }
};
