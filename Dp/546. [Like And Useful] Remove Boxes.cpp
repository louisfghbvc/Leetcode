// O(N^4). hard to think, self-contained
// two case.
// case1 is if use this, say (k+1)*(k+1). and go right. k box = 0
// case2. Enum all break point. say if j == left, save left, box + 1, transition dfs(j, r, k+1). and [l+1, j-1] box is 0, cuz l == j. dfs.

class Solution {
public:
    vector<int> arr;
    int dp[105][105][105];
    int dfs(int l, int r, int k){
        if(l > r) return 0;
        if(dp[l][r][k] != -1) return dp[l][r][k];
        for(; l < r && arr[l] == arr[l+1]; l++, k++);
        int res = (k+1)*(k+1) + dfs(l+1, r, 0);
        for(int j = l+1; j <= r; ++j){
            if(arr[l] == arr[j])
                res = max(res, dfs(l+1, j-1, 0) + dfs(j, r, k+1));
        }
        return dp[l][r][k] = res;
    }
    int removeBoxes(vector<int>& boxes) {
        arr = boxes;
        memset(dp, -1, sizeof dp);
        return dfs(0, arr.size()-1, 0);
    }
};
