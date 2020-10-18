// WA... 2 times... omg.
// O(N^2). Enum all postition and just maintain max.
// Wait, this is Fail.
// [[1,0,2],[0,1,2],[2,1,2],[1,2,2]] 1, is [1,1]
// not always tower position.
class Solution {
public:
    double dis(int x1, int y1, int x2, int y2){
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int n = towers.size();
        int mx = 0;
        vector<int> res = {105, 105};
        for(int i = 0; i < n; ++i){
            int x = towers[i][0], y = towers[i][1], q = towers[i][2];
            int sum = q;
            for(int j = 0; j < n; ++j){
                int x2 = towers[j][0], y2 = towers[j][1], q2 = towers[j][2];
                if(i == j || dis(x, y, x2, y2) > radius) continue;
                sum += q2/(1+dis(x, y, x2, y2));
            }
            if(sum > mx){
                mx = sum;
                res = {x, y};
            }
            else if(sum == mx){
                if(x < res[0] || (x == res[0] && y < res[1])) res = {x, y};
            }
        }
        
        return res;
    }
};

// O(N^3). this is correct.
class Solution {
public:
    double dis(int x1, int y1, int x2, int y2){
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int n = towers.size();
        int mx = 0;
        vector<int> res = {105, 105};
        for(int x = 0; x <= 50; ++x){
            for(int y = 0; y <= 50; ++y){
                int sum = 0;
                for(int i = 0; i < n; ++i){
                    int x2 = towers[i][0], y2 = towers[i][1], q = towers[i][2];
                    if(dis(x, y, x2, y2) > radius) continue;
                    sum += q/(1+dis(x, y, x2, y2));
                }
                if(sum > mx){
                    mx = sum;
                    res = {x, y};
                }
                else if(sum == mx){
                    if(x < res[0] || (x == res[0] && y < res[1])) res = {x, y};
                }
            }
        }
        
        return res;
    }
};
