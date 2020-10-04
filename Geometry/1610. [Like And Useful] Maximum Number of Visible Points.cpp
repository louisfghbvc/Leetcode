// circle sliding, atan2 = [-pi, pi].
// so change to atan2, and sort. after sort add self + 2*pi. so that can solve the circle.
// a special case is self point. 0 0.
// and use sliding window to maintain window size < angle.
// O(NlogN).

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        const double PI = acos(-1);
        int px = location[0], py = location[1];
        vector<double> arr;
        
        int ans = 0;
        for(auto &p: points){
            p[0] -= px, p[1] -= py;
            if(p[0] == 0 && p[1] == 0) ans++;
            else arr.push_back(atan2(p[1], p[0]));
        }
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; ++i) arr.push_back(arr[i]+PI*2);
        
        
        int cnt = 0;
        double rad = 1.0*angle*PI/180;
        for(int r = 0, l = 0; r < 2*n; r++){
            while(l < r && arr[r]-arr[l] > rad + 1e-8) l++;
            cnt = max(cnt, r-l+1);
        }
        
        return ans + cnt;
    }
};
