// O(NlogN). just sort left and shrink area.

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(!n) return 0;
        
        sort(points.begin(), points.end());
        int cnt = 1;
        int l = points[0][0], r = points[0][1];
        for(int i = 1; i < n; ++i){
            if(points[i][0] >= l && points[i][0] <= r){
                l = max(l, points[i][0]);
                r = min(r, points[i][1]);
            }
            else l = points[i][0], r = points[i][1], cnt++;
        }
        return cnt;
    }
};

// Sort by right. same as non-overlapping problem greedy.
// O(NlogN).
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(!n) return 0;
        
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        
        int cnt = 1;
        int r = points[0][1];
        for(int i = 1; i < n; ++i){
            if(points[i][0] > r){
                r = points[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};
