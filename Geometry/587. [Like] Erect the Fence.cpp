// Convell hull O(NlogN). just careful line.


class Solution {
public:
    int cross(vector<int> &o, vector<int> &a,  vector<int> &b){
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]); 
    }
    
    vector<vector<int>> convex_hull(vector<vector<int>> &points){
        int n = points.size();
        sort(points.begin(), points.end());
        vector<vector<int>> res(2*n);
        // down convex
        int k = 0;
        for(int i = 0; i < n; ++i){
            while(k > 1 && cross(res[k-2], res[k-1], points[i]) < 0) k--;
            res[k++] = points[i];
        }
        // line
        if(k == n){
            res.resize(k);
            return res;
        }
        // up convex
        for(int i = n-2, t = k; i >= 0; --i){ // no need to do end
            while(k > t && cross(res[k-2], res[k-1], points[i]) < 0) k--;
            res[k++] = points[i];
        }  
        k--; // begin must put again
        res.resize(k);
        return res;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        return convex_hull(points);
    }
};
