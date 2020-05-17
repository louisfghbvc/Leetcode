// hard to think. math..
// O(N^3) not optimal.
class Solution {
public:
    const double eps = 1e-6;
    struct P{
        double x, y;
    };
    vector<P> point;
    double R;
    double dis(const P &a, const P &b){
        return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    }
    pair<P, P> getCircle(P &a, P &b){
        P mid;
        pair<P, P> res;
        mid.x = (a.x+b.x)/2.0; 
        mid.y = (a.y+b.y)/2.0;
        
        double theta = atan2(a.y-b.y, b.x-a.x);
        double ml = dis(a, b)/2.0;
        double d = sqrt(R*R - ml*ml);
        
        res.first.x = mid.x - d*sin(theta); 
        res.first.y = mid.y - d*cos(theta);
        res.second.x = mid.x + d*sin(theta); 
        res.second.y = mid.y + d*cos(theta);
        return res;
    }
    int numPoints(vector<vector<int>>& points, int r) {
        int n = points.size();
        R = r;
        point.resize(n);
        for(int i = 0; i < n; ++i){
            point[i].x = points[i][0];
            point[i].y = points[i][1];
        }
        int mx = 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j || dis(point[i], point[j]) - 2*R > eps) continue;
                auto tp = getCircle(point[i], point[j]);
                int cnt = 0;
                for(int k = 0; k < n; ++k){
                    if(dis(point[k], tp.first) - R <= eps) cnt++;
                }
                mx = max(mx, cnt);
                cnt = 0;
                for(int k = 0; k < n; ++k){
                    if(dis(point[k], tp.second) - R <= eps) cnt++;
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};
