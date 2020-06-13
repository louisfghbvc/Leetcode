// Nice, Three times complete contest.
// O(N^3) , md is pre mid.
// and enum all case. maintain minimum. not optimal.
class Solution {
public:
    int n;
    vector<int> arr;
    int dp[105][105][105];
    int dfs(int k, int l, int r, int md){
        if(k == 0){
            if(l >= r) return 0;
            int c = 0;
            for(int i = l; i < r; ++i) c+=abs(arr[i]-md);
            return c;
        }
        if(l >= r) return 1e9;
        if(dp[k][l][r] != -1) return dp[k][l][r];
        int res = INT_MAX;
        for(int i = l; i < r; ++i){
            int len = i-l+1, mid, c = 0;
            if(len%2){
                mid = arr[l+len/2];
                for(int j = l; j <= i; ++j) c += abs(arr[j]-mid);
                // printf("%d %d %d %d\n", l, i, mid, c);
                res = min(c+dfs(k-1, i+1, r, mid), res);
            }
            else{
                mid = (arr[l+(len/2-1)]+arr[l+(len/2)])/2;
                for(int j = l; j <= i; ++j) c += abs(arr[j]-mid);
                // printf("%d %d %d %d\n", l, i, mid, c);
                res = min(c+dfs(k-1, i+1, r, mid), res);
            }
        }
        return dp[k][l][r] = res;
    }
    int minDistance(vector<int>& houses, int k) {
        memset(dp, -1, sizeof dp);
        sort(houses.begin(), houses.end());
        n = houses.size();
        arr = houses;
        return dfs(k, 0, n, 0);
    }
};
