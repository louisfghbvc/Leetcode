// O(N^2F). 
// determine the base case.
// and just do it. because current be end point can still walking. so not return and res = 1.
// and Memorize. nothing special, a classic dp

class Solution {
public:
    const int mod = 1e9+7;
    vector<int> arr;
    int n;
    int dp[105][205];
    int dfs(int i, int ed, int f){
        if(dp[i][f] != -1) return dp[i][f];
        int res = 0;
        if(i == ed){
            res = 1;
        }
        for(int j = 0; j < n; ++j){
            if(j == i) continue;
            int c = abs(arr[j]-arr[i]);
            if(f >= c){
                res = (res + dfs(j, ed, f-c)) % mod;
            }
        }
        return dp[i][f] = res;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof dp);
        arr = locations;
        n = arr.size();
        return dfs(start, finish, fuel);
    }
};
