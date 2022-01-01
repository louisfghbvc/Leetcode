// top-down, memorization
// trick O(N)

class Solution {
public:
    
    int dfs(int prev_a, int prev_b, int i, bool swapped){
        if(i == a.size()) return 0;
        
        int &res = dp[i][swapped];
        if(res != -1) return res;
        
        res = 1e9;
        // no swap
        if(a[i] > prev_a && b[i] > prev_b)
            res = min(res, dfs(a[i], b[i], i+1, 0));
        // swap
        if(b[i] > prev_a && a[i] > prev_b)
            res = min(res, 1+dfs(b[i], a[i], i+1, 1));
        
        return res;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        a = nums1, b = nums2;
        dp = vector<vector<int>>(a.size(), vector<int>(2, -1));
        return dfs(-1, -1, 0, 0);
    }
    
private:
    vector<int> a, b;
    vector<vector<int>> dp;
};
