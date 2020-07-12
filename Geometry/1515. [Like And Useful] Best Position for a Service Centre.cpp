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
// 8ms. Super Fast.
// Walker Test. 4 direction explore. when not found. update precision. Like Gradient Descendent
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    double getMinDistSum(vector<vector<int>>& positions) {
        double steps = 100, eps = 1e-6;
        double res = DBL_MAX;
        
        auto f = [&](double x, double y){
            double dis = 0.0;
            for(auto &p: positions)
                dis += sqrt((x-p[0])*(x-p[0])+(y-p[1])*(y-p[1]));
            return dis;
        };
        
        double px = 0.0, py = 0.0;
        while(steps > eps){
            bool found = false;
            for(int k = 0; k < 4; ++k){
                double npx = px + steps*dir[k][0];
                double npy = py + steps*dir[k][1];
                double d = f(npx, npy);
                if(d < res){
                    res = d;
                    px = npx, py = npy;
                    found = true;
                }
            }
            if(!found) steps /= 10;
        }
        
        return res;
    }
};
