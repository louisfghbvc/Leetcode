// O(N^2). hash the distance
// and calculate the number of ways.
// C n choose 2

class Solution {
public:
    
    int distance(vector<int> &a, vector<int> &b){
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            unordered_map<int, int> mp;
            for(int j = 0; j < n; ++j) if(j != i){
                mp[distance(points[i], points[j])]++;
            }
            for(auto &[k, v]: mp)
                cnt += v * (v-1);
        }
        
        return cnt;
    }
};
