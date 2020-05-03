// Very hard problem. change choose hat to choose person. 
// save each hat state 1024.
// base is all person choose a hat. 1
// hat over 40 is 0.
// dp is choose this hat(then that hat's person if not choose before then choose =  choose|(1 << person) ) + not choose this hat.
// then get ans. very hard think problem
static int fast = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 1;
}();
class Solution {
public:
    const int mod = 1e9+7;
    vector<int> h2p[42];
    vector<vector<int>> memo;
    int dfs(int allmask, int choose, int hat){
        if(choose == allmask) return 1;
        if(hat > 40) return 0;
        if(memo[hat][choose] != -1) return memo[hat][choose];
        
        int res = dfs(allmask, choose, hat+1);
        for(auto &person: h2p[hat]){
            if((1<<person) & choose) continue;
            res += dfs(allmask, choose|(1<<person), hat+1);
            res %= mod;
        }
        
        return memo[hat][choose] = res;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> t(42, vector<int>(1024, -1));
        memo = t;
        for(int i = 0; i < n; ++i){
            for(const auto &h: hats[i]){
                h2p[h].push_back(i);    
            }
        }
        return dfs((1<<n)-1, 0, 1);
    }
};
