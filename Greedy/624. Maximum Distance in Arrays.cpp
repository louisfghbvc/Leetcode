// since is maximum distance
// so just choose the edge point, minimum and maximum.
// time O(N), space O(1)

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // each choose the edge point
        // minimum and maximum
        
        int mx = arrays[0].back(), mn = arrays[0][0];
        int res = 0;
        
        // mx - v_min
        // v_max - mn
        for(int i = 1; i < arrays.size(); ++i){
            auto &v = arrays[i];
            res = max({res, mx - v[0], v.back() - mn});
            // update the minimum, maximum so far
            mn = min(v[0], mn);
            mx = max(v.back(), mx);
        }
        
        return res;
    }
};
