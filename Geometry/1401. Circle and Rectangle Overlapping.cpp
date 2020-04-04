//circle in rectangle or rectangle in circle. O(N) 
//0ms 6.1MB
class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        auto inside = [&](int x, int y){
            return abs(x - xc)*abs(x - xc) + abs(y - yc)*abs(y - yc) <= r*r;
        };
        if(x1 <= xc && y1 <= yc && x2 >= xc && y2 >= yc) return 1;
        for(int x = x1; x <= x2; ++x)
            if(inside(x, y1) || inside(x, y2)) return 1;
        for(int y = y1; y <= y2; ++y)
            if(inside(x1, y) || inside(x2, y)) return 1;
        return 0;
    }
};


//Super easy math closest point in rectangle
class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int dx = xc - max(x1, min(xc, x2));
        int dy = yc - max(y1, min(yc, y2));
        return dx*dx + dy*dy <= r*r;
    }
};
