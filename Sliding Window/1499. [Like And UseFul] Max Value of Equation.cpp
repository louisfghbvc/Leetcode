// O(NlogN). because xi < xj
// and |xi-xj| < k
// yi + yj + |xi-xj| max, and j<i
// so = yi-xi + yj+xj
// maintain max yi-xi, and index xi to check is over k

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size(), ans = INT_MIN;
        priority_queue<pair<int, int>> pq;
        for(auto &p: points){
            while(pq.size() && (p[0]-pq.top().second) > k) pq.pop();
            if(pq.size()){
                ans = max(ans, pq.top().first + p[0]+p[1]);
            }
            pq.push({p[1]-p[0], p[0]});
        }
        return ans;
    }
};

// Can Optimal to monoqueue O(N). Same as slidind window concept.
