// because filp 2 times is no use. so each position filp one time.
// enum all case. and the permutation is no use. if filp 123 same as 321, 213...
// O(2^(n*m)*n*m*4)

class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool ok(vector<vector<int>> &m){
        for(auto &r: m)
            for(auto &c: r)
                if(c) return false;
        return true;
    }
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int k = n * m, res = 20;
        for(int i = 0; i < (1<<k); ++i){
            vector<vector<int>> tmp = mat;
            for(int j = 0; j < k; ++j){
                if(i & (1<<j)){
                    int x = j/m, y = j%m;
                    tmp[x][y] ^= 1;
                    for(int t = 0; t < 4; ++t){
                        int nx = x + dir[t][0], ny = y + dir[t][1];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        tmp[nx][ny] ^= 1;
                    }
                }
            }
            if(ok(tmp)) res = min(res, __builtin_popcount(i));
        }
        return res == 20 ? -1 : res;
    }
};
