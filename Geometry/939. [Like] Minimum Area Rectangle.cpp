// just fix left-top and right-down
// O(N^4)

class Solution {
public:
    
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        int res = 1e9;
        
        // x->y
        unordered_map<int, unordered_set<int>> mp;
        for(auto &p: points)
            mp[p[0]].insert(p[1]);
        
        // fix left-top points
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j) if(i != j && points[i][0] < points[j][0] && points[i][1] < points[j][1]){
                int left_x = points[i][0], left_y = points[i][1]; 
                int right_x = points[j][0], right_y = points[j][1];
                if(mp[right_x].count(left_y) && mp[left_x].count(right_y))
                    res = min((right_x - left_x) * (right_y - left_y), res);
            }
        }
        
        return res == 1e9 ? 0 : res;
    }
};
