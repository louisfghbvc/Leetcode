vector<int> dis[2500];

class Solution {
public:

    vector<int> minMove(int x, int y) {
        vector<int> res(2500, -1);
        res[x*50+y] = 0;
        queue<pair<int, int>> q;
        q.push({x, y});
        int dep = 1;
        while (q.size()) {
            for (int sz = q.size(); sz > 0; --sz) {
                auto [x, y] = q.front(); q.pop();
                for (int dx = -2; dx <= 2; ++dx) {
                    for (int dy = -2; dy <= 2; ++dy) {
                        if (abs(dx) + abs(dy) != 3) continue;
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || nx >= 50 || ny < 0 || ny >= 50) continue;
                        if (res[nx*50+ny] == -1) {
                            res[nx*50+ny] = dep;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            dep++;
        }

        return res;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        // goal: max moves
        // A => max, B => min
        // given knight, A want to maximum the moves

        // idea:
        // knight => compute the minimum distance to all position
        // we can move the knight to new postitions
        // shortest path from any position
        // precompute O(50^4) 
        // convert to 1D

        // game dp + bitmask
        // dp[i][mask] => moves + max {try each position not in mask}, i=0~n-1
        // i we can just using index, since we only have n+1 distinct position!

        // precompute        
        if (dis[0].empty()) {
            for (int i = 0; i < 50; ++i) {
                for (int j = 0; j < 50; ++j) {
                    dis[i*50+j] = minMove(i, j);
                }
            }
        }
        
        positions.insert(positions.begin(), {kx, ky});
        int n = positions.size();
        vector dp(n, vector(1<<n, vector(2, -1)));
        auto dfs = [&](auto &self, int i, int mask, int isA=1) {
            if (mask == 0) return 0;

            int &res = dp[i][mask][isA];
            if (res != -1) return res;

            res = isA ? -1e7 : 1e9;
            int cur = positions[i][0]*50+positions[i][1];
            for (int j = 0; j < n; ++j) {
                if (mask >> j & 1) {
                    int next = positions[j][0]*50+positions[j][1];
                    if (isA) {
                        res = max(res, dis[cur][next] + self(self, j, mask^(1<<j), 0));
                    }
                    else {
                        res = min(res, dis[cur][next] + self(self, j, mask^(1<<j), 1));
                    }
                }
            }

            return res;
        };

        return dfs(dfs, 0, ((1<<n)-1)^1);
    }
};
