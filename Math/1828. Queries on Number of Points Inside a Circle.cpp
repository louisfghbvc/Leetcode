// O(NM). just brute force

class Solution {
public:
    int dis(int x, int y, int x2, int y2){
        return (x-x2)*(x-x2) + (y-y2)*(y-y2);
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto &q: queries){
            int x = q[0], y = q[1], r = q[2];
            int cnt = 0;
            for(auto &p: points){
                if(dis(x, y, p[0], p[1]) <= r*r) cnt++;
            }
            res.push_back(cnt);
        }
        
        return res;
    }
};
