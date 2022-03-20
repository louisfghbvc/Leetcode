// top-down memo
// O(NK)

class Solution {
public:
    
    int dfs(int i, int num) {
        if (i >= s.size()) return 0;
        int &res = dp[i][num];
        if (res != -1) return res; // visited
        
        // no use
        res = (s[i] == '1') + dfs(i+1, num);
        // use
        if (num)
            res = min(res, dfs(i+len, num-1));
        
        return res;
    }    

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        s = floor;
        dp = vector<vector<int>> (floor.size(), vector<int>(numCarpets+1, -1));
        len = carpetLen;
        // goal: minimum the '1'
        // use or no use
        // minimum number of 1
        // dp[i][numCarpets] = dp[i+carpetLen][numCarpets-1] or cost + dp[i+1][numCarpets]
        return dfs(0, numCarpets);
    }
    
private:
    vector<vector<int>> dp;
    int len;
    string s;
};
