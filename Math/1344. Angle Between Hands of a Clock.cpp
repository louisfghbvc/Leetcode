// calculate minutes.
// 1 minute. hour move 0.5 degree

class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double h = hour*30 + (double)minutes*0.5;
        double res = abs(h-minutes*6);
        return res > 180 ? 360-res: res;
    }
};
