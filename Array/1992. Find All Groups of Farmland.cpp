// just ask the constraint. the farmland is rectangle.
// so just go side length.
// T:O(MN). S:O(1)

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int n = land.size(), m = land[0].size();
        
        auto fill = [&](int r1, int c1, int r2, int c2){
            for(int i = r1; i < r2; ++i)
                for(int j = c1; j < c2; ++j)
                    land[i][j] = 0;
        };
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!land[i][j]) continue;
                int ni = i, nj = j;
                while(ni < n && land[ni][j]) ni++;
                while(nj < m && land[i][nj]) nj++;
                fill(i, j, ni, nj);
                res.push_back({i, j, ni-1, nj-1});
            }
        }
        
        return res;
    }
};
