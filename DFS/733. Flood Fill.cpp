// Care that new image can not be old image. or stack overflow. then simple.
// check edge case. O(N)
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m, n;
    void dfs(vector<vector<int>>& image, int x, int y, int newColor, int oC){
        if(x < 0 || y < 0 || x >= m || y >= n || image[x][y] != oC) return;
        image[x][y] = newColor;
        for(int i = 0; i < 4; ++i){
            dfs(image, x+dir[i][0], y+dir[i][1], newColor, oC);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size(); n = image[0].size();
        if(image[sr][sc] != newColor)
            dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};
