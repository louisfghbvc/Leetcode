// First get col max, second get row max, then row*col % mod.
// O(N)

class Solution {
public:
    const int mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(verticalCuts.begin(), verticalCuts.end());
        sort(horizontalCuts.begin(), horizontalCuts.end());
        int c = verticalCuts.size(), r = horizontalCuts.size();
        int x = 0, mxx = INT_MIN;
        for(int i = 0; i < c; ++i){
            mxx = max(mxx, verticalCuts[i]-x);
            x = verticalCuts[i];
        }
        mxx = max(mxx, w-x);
        int y = 0, mxy = INT_MIN;
        for(int i = 0; i < r; ++i){
            mxy = max(mxy, horizontalCuts[i]-y);
            y = horizontalCuts[i];
        }
        mxy = max(h-y, mxy);
        
        return (long)mxy*mxx%mod;
    }
};
