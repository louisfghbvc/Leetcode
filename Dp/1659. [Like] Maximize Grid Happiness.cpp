// OK. very very hard...
// magic of use of rolling bitmask. use bitmask to speed up sum.
// and just like backtracking 3 case.

class Solution {
public:
    int m, n;
    int dp[30][7][7][1<<6][1<<6];
    
    int nCost(int i, int j, int mask_in, int mask_ex, int d){
        int up = 1<<(n-1), diff = 0;
        if(j > 0 && (mask_in & 1)) // left, right has neighbor
            diff += d - 30;
        if(i > 0 && (mask_in & up)) // up, down has neighbor
            diff += d - 30;
        if(j > 0 && (mask_ex & 1))
            diff += d + 20;
        if(i > 0 && (mask_ex & up))
            diff += d + 20;
        return diff;
    }
    
    int dfs(int id, int iC, int eC, int mask_in, int mask_ex){
        if(id >= m*n) return 0;
        if(dp[id][iC][eC][mask_in][mask_ex] != -1) return dp[id][iC][eC][mask_in][mask_ex];
        
        int i = id/n, j = id%n;
        int nin = (mask_in<<1) & 63, nex = (mask_ex<<1) & 63; // rolling bitmask
        
        int res = dfs(id+1, iC, eC, nin, nex);    
        if(iC){
            int diff = 120 + nCost(i, j, mask_in, mask_ex, -30);
            res = max(res, diff + dfs(id+1, iC-1, eC, nin+1, nex));
        }
        
        if(eC){
            int diff = 40 + nCost(i, j, mask_in, mask_ex, 20);
            res = max(res, diff + dfs(id+1, iC, eC-1, nin, nex+1));
        }
        
        return dp[id][iC][eC][mask_in][mask_ex] = res;
    }
    int getMaxGridHappiness(int m, int n, int iC, int eC) {
        memset(dp, -1, sizeof dp);
        this->m = m; this->n = n;
        return dfs(0, iC, eC, 0, 0);
    }
};

// 3 base bitmask
