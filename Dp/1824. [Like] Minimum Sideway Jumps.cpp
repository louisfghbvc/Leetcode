// O(N). bottom up. just consider from next and get minimum

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<int> now(4), next(4);
        now[1] = now[3] = 1;
        for(int i = 0; i < obstacles.size(); ++i){
            next = now;
            next[obstacles[i]] = 1e9;
            int mn = min({next[1], next[2], next[3]});
            for(int j = 1; j <= 3; ++j){
                if (obstacles[i] != j)
                    next[j] = min(next[j], mn + 1);
            }
            now = next;
        }
        return min({now[1], now[2], now[3]});
    }
};

// top down dp
class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& ob, int x, int y){
        if(x+1 == ob.size()) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        int res = 1e9;
        if(ob[x+1] == y){
            if(y > 1){
                if(y - 2 > 0 && y - 2 != ob[x])
                    res = min(res, 1 + dfs(ob, x, y-2));
                if(y - 1 != ob[x])
                    res = min(res, 1 + dfs(ob, x, y-1));
            }
            if(y < 3){
                if(y + 2 <= 3 && y + 2 != ob[x])
                    res = min(res, 1 + dfs(ob, x, y+2));
                if(y + 1 != ob[x])
                    res = min(res, 1 + dfs(ob, x, y+1));
            }
        }
        else res = dfs(ob, x+1, y);
        return dp[x][y] = res;
    }
    int minSideJumps(vector<int>& obstacles) {
        dp = vector<vector<int>> (obstacles.size(), vector<int>(4, -1));
        return dfs(obstacles, 0, 2);
    }
};
