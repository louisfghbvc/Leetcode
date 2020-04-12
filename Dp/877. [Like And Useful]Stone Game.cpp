//Minimax
class Solution {
public:
    int memo[505][505][2] = {};
    
    int dfs(int l, int r, bool alex, vector<int>& piles){
        if(l > r) return 0;
        if(memo[l][r][alex]) return memo[l][r][alex];
        int res = alex ? INT_MIN : INT_MAX;
        if(alex){
            res = max(piles[l] + dfs(l+1, r, 0, piles), piles[r] + dfs(l, r-1, 0, piles));
        }
        else{
            res = min(-piles[l] + dfs(l+1, r, 1, piles), -piles[r] + dfs(l, r-1, 1, piles));
        }
        return memo[l][r][alex] = res;
    }
    
    bool stoneGame(vector<int>& piles) {
        return dfs(0, piles.size()-1, 1, piles) > 0;
    }
};
