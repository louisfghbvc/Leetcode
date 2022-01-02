// O(NlogN)
// tricky
// move until greater
// or move middle
// |---------------|
//     <-------
//     ------------>

class Solution {
public:
    vector<int> dp;
    
    int dfs(int i){
        
        int &res = dp[i];
        if(res != -1) return res;
        
        res = 1e9;
        // m: move
        int j = 1, m = 1;
        for(; j < i; ++m, j = (1<<m)-1){
            for(int p = 0, q = 0; p < j; ++q, p = (1<<q)-1){
                res = min(res, m + 1 + q + 1 + dfs(i - j + p));
            }
        }
        
        res = min(res, m + (i == j ? 0 : 1 + dfs(j - i)));    
    
        return res;
    }
    
    int racecar(int target) {
        dp = vector<int>(target+1, -1);
        return dfs(target);
    }
};
