// Enum two points. O(N^3).
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int cnt = 2;
                for(int k = 0; k < n; ++k) if(k != i && k != j){
                    // vertical
                    if(points[i][0] == points[j][0]){
                        if(points[k][0] == points[i][0]) cnt++;
                    }
                    else{
                        if((points[i][1] - points[j][1]) * (points[k][0] - points[j][0])
                           == (points[k][1] - points[j][1]) * (points[i][0] - points[j][0]))
                            cnt++;
                    }
                }
                res = max(cnt, res);
            }
        }
        
        return res;
    }
};

// Enum one points. calc slope. use hash table
// Why gcd? since (8, 4) (4, 2) is same slope
// O(N^2).
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            map<pair<int, int>, int> mp;
            int dup = 1;
            for(int j = i+1; j < n; ++j){
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1]) dup++;
                else{ // slope
                    int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1];
                    int g = __gcd(dx, dy);
                    mp[{dy / g, dx / g}]++;
                }
            }
            
            for(auto &[_, f]: mp)
                res = max(res, dup + f);
        }
        
        return res;
    }
};
