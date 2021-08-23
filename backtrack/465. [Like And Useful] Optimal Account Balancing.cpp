// np-complete problem, Hard to think, so we first build array, and try all candidate.
// O(N!)
class Solution {
public:
    vector<int> debt;
    
    int dfs(int i){
        while(i < debt.size() && !debt[i]) i++;
        if(i == debt.size()) return 0;
        int res = INT_MAX;
        for(int j = i+1; j < debt.size(); ++j){
            if(debt[i] * debt[j] < 0){ // oppsite sign
                debt[j] += debt[i];
                res = min(res, 1 + dfs(i+1)); // drop i
                debt[j] -= debt[i];
            }
        }
        return res;
    }
    
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> mp;
        for(auto &t: transactions){
            mp[t[0]] -= t[2];
            mp[t[1]] += t[2];
        }
        
        for(auto &[_, v]: mp) if(v != 0) debt.push_back(v);
        
        return dfs(0);
    }
};
