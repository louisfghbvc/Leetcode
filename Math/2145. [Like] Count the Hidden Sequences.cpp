// only compute the edge value. minimum and maximum so far
// O(N)
// and compute ans - not valid upperbound and lowerbound

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        // normalize
        upper -= lower;
        lower = 0;
        
        long base1 = lower, base2 = upper;
        long mn = INT_MAX, mx = INT_MIN;
        for(int x: differences){
            base1 += x;
            base2 += x;
            mn = min(base1, mn);
            mx = max(base2, mx);
        }
        int res = (upper-lower+1) - max(0L, mx - upper) - max(0L, lower - mn);
        return max(0, res);
    }
};
