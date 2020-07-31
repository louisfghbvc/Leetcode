// So the uniform. use sqrt make line smooth
// and use Polar Coordinates, because the problem say.
// a point on the circumference of the circle is considered to be in the circle.

#define PI acos(-1)
class Solution {
public:
    double x, y, r;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    double unit(){
        return (double)rand()/RAND_MAX;
    }
    vector<double> randPoint() {
        double theta = 2*PI*unit();
        double rr = sqrt(unit());
        return {x + r * rr * cos(theta), y + r * rr * sin(theta)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
