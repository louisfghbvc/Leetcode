// O(N).
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if(a > b) return maximumScore(b, a, c);
        if(a > c) return maximumScore(c, b, a);
        if(b > c) return maximumScore(a, c, b);
        int ab = a+b;
        if(ab <= c) return ab;
        int res = 0;
        for(int l = 1, r = c-1; l <= r; ++l, --r){
            if(a-l > 0 && b-r > 0){
                res = max(res, min(a-l, b-r));
            }
            if(a-r > 0 && b-l > 0){
                res = max(res, min(a-r, b-l));
            }
        }
        return c + res;
    }
};

// O(1). trick...
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        return min( (a+b+c)/2, a+b+c - max({a, b, c}) ); 
    }
};

// O(1). more understandable
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if(a > b) swap(a, b);
        if(a > c) swap(a, c);
        if(b > c) swap(b, c);
        if(a + b < c) return a+b;
        return (a+b+c)/2;
    }
};
