// main idea is LIS. and how to sort it.
// can rotate so first sort each item.
// then how to sort cuboids? u can sort by volume. or just default. it can compare [0] then [1] then [2].
// O(N^2)

class Solution {
public:
    bool canP(vector<int> &a, vector<int> &b){
        return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &c: cuboids)
            sort(c.begin(), c.end());
        
        sort(cuboids.begin(), cuboids.end());
        
        int n = cuboids.size();
        vector<int> dp(n);
        
        for(int i = 0; i < n; ++i){
            dp[i] = cuboids[i][2];
            for(int j = i-1; j >= 0; --j){
                if(canP(cuboids[j], cuboids[i])){
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
