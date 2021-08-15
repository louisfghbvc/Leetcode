// Union Find, try to connect first row, and last row.
// O(row * col)

class Solution {
public:
    vector<int> p;
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        p[y] = x;
    }
    
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 1));
        p = vector<int>(row*col + 3, -1);
        
        int startG = row*col+1, endG = row*col+2;
        for(int j = 0; j < col; j++){
            uni(j, startG);
            uni((row-1)*col + j, endG);
        }
        
        for(int i = row*col-1; i >= 0; --i){
            int r = cells[i][0]-1, c = cells[i][1]-1;
            grid[r][c] = 0;
            int key = r*col + c;
            for(int k = 0; k < 4; ++k){
                int nr = r+dir[k][0], nc = c+dir[k][1];
                if(nr >= 0 && nr < row && nc >= 0 && nc < col && !grid[nr][nc]){
                    int nkey = nr*col + nc;
                    uni(key, nkey);
                }
                if(find(startG) == find(endG)){
                    return i;
                }
            }
        }
        
        return row*col-1;
    }
};
