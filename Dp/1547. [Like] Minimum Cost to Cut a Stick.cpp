// So change array like prefix. because cost is length.
// so arr[r]-arr[l].
// and enum in l~r. remember k can overlap.
// think about cuts[1 3 4 5]
// so array = [0, 1, 3, 4, 5, 7]
// and if first cut. cost must = 7-0.
// and can choose 1345 right?
// and when choose 1, so divide 0 1, 1 3 4 5 7. that's why k reuse.
// O(N^3) uva problem

class Solution {
public:
    int dp[105][105];
    int dfs(vector<int>& arr, int l, int r){
        if(r-l < 2) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int res = arr[r]-arr[l];
        int mn = 1e9;
        for(int k = l+1; k < r; ++k){
            mn = min(mn, dfs(arr, l, k)+dfs(arr, k, r));
        }
        return dp[l][r] = res + mn;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof dp);
        vector<int> arr(1, 0);
        arr.insert(arr.end(), cuts.begin(), cuts.end());
        arr.push_back(n);
        return dfs(arr, 0, arr.size()-1);
    }
};
