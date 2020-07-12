// Solution1 Precision Shrink. Find mean
// find rect, and step is 1.
// second epoch step = 0.1
// third epoch step = 0.01
// ...
// 384ms 7.9MB
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double l = 100, r = 0, d = 100, u = 0; // rect: left, right, bottom, top
        for(const auto&p: positions){
            l = min((double)p[0], l);
            r = max((double)p[0], r);
            d = min((double)p[1], d);
            u = max((double)p[1], u);
        }
        double res = DBL_MAX, res_x = 0, res_y = 0;
        for(double delta = 1.0; delta >= 1e-4; delta /= 10){
            for(double x = l; x <= r; x += delta){
                for(double y = d; y <= u; y += delta){
                    double dis = 0;
                    for(const auto&p: positions)
                        dis += sqrt((x-p[0])*(x-p[0])+(y-p[1])*(y-p[1]));
                    if(dis < res){
                        res = dis;
                        res_x = x;
                        res_y = y;
                    }
                }
            }
            l = res_x - delta;
            r = res_x + delta;
            d = res_y - delta;
            u = res_y + delta;
        }
        return res == DBL_MAX ? 0 : res;
    }
};

// Solution2 https://www.geeksforgeeks.org/geometric-median/
