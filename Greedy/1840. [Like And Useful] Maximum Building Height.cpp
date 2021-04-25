// Setting the bound from left to right, and reverse. make sure bound is correct
// After that just try to get the ans

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n-1});
        sort(restrictions.begin(), restrictions.end());
        
        int N = restrictions.size();
        // left to right. update the restrictions
        for(int i = 1; i < N; ++i){
            int up = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + up);
        }
        for(int i = N-2; i >= 0; --i){
            int up = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + up);
        }
        
        int res = 0;
        for(int i = 0; i+1 < N; ++i){
            int x1 = restrictions[i][0], x2 = restrictions[i+1][0];
            int h1 = restrictions[i][1], h2 = restrictions[i+1][1];
            
            // abs(h1 - h2): make h1, h2 the same
            res = max(res, max(h1, h2) + (x2 - x1 - abs(h1 - h2) ) / 2);
            
        }
        
        return res;
    }
};
