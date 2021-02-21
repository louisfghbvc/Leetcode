// Greedy magic. O(logY)
// We work backward. why
// cuz, we don't know what to do is better when transfer x to y.

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X >= Y) return X - Y;
        int res = 0;
        while(X < Y){
            if(Y & 1) Y++;
            else Y >>= 1;
            res++;
        }
        return res + X - Y;
    }
};
