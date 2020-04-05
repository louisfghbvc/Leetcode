//O(N). Minimax.
class Solution {
public:
    int memo[50001] = {};
    
    int dfs(vector<int>& stoneValue, int idx){
        if(idx >= stoneValue.size()) return 0;
        if(memo[idx]) return memo[idx];
        int res = INT_MIN, sum = 0;
        for(int i = 0; i < 3 && idx + i < stoneValue.size(); ++i){
            sum += stoneValue[idx + i]; //one person take
            res = max(res, sum - dfs(stoneValue, idx + i + 1)); // max(me - other person take)
        }
        return memo[idx] = res;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int judge = dfs(stoneValue, 0);
        if(judge > 0)
            return "Alice";
        else if(judge < 0)
            return "Bob";
        return "Tie";
    }
};
