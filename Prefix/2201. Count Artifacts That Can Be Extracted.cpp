// use 2D prefix 
// O(N)
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        // use 2D prefix sum to record the number of dig
        // 1. set dig
        // 2. do prefix sum
        // 3. for each artifacts, check the range is zero or not
        
        vector<vector<int>> grid(n+1, vector<int>(n+1, 1));
        
        for(auto &d: dig)
            grid[d[0]+1][d[1]+1] = 0;
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]; 
            }
        }

        int cnt = 0;
        for(auto &a: artifacts){
            int r1 = a[0], c1 = a[1], r2 = a[2], c2 = a[3];
            if(grid[r2+1][c2+1] - grid[r2+1][c1] - grid[r1][c2+1] + grid[r1][c1] == 0) cnt++;
        }
        return cnt;
    }
};

// autually no need, since all artifact is not intersect with each other 
