// since uniform. and u need to balance the probability. according to x^2 + y^2 = r.
// so r need sqrt.

class Solution {
public:
    #define PI acos(-1)
    double r, x, y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    double unit(){
        return (double)rand() / RAND_MAX;
    }
    
    vector<double> randPoint() {
        double sieta = 2*PI*unit();
        double percent = sqrt(unit());
        return {x + r * percent * cos(sieta), y + r * percent * sin(sieta)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
