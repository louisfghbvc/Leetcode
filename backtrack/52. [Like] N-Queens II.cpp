// 4ms, Just Simulate. abs caculate slope. pos or neg cannot exist.
class Solution {
public:
    vector<int> queen;
    int ans;
    bool canPlace(int k){
        for(int i = 0; i < k; ++i){
            if(queen[i] == queen[k] || abs(queen[k]-queen[i]) == abs(k - i))
                return 0;
        }
        return 1;
    }
    void dfs(int k, int n){
        if(k == n){
            ans++; return;
        }
        for(int col = 0; col < n; ++col){
            queen[k] = col;
            if(canPlace(k)){
                dfs(k+1, n);
            }
        }
    }
    int totalNQueens(int n) {
        ans = 0;
        queen.resize(n);
        dfs(0, n);
        return ans;
    }
};
