// Almost timelimit. 952ms
// Simple.
// O(N^2*m)
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        vector<unordered_set<string>> fc;
        for(int i = 0; i < n; ++i){
            unordered_set<string> tmp(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
            fc.push_back(tmp);
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            bool sb = 0;
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                bool ok = 1;
                for(const auto&x : fc[i]){
                    if(!fc[j].count(x)){
                        ok = 0;
                        break;
                    }
                }
                if(ok) sb = 1;
            }
            if(!sb) ans.push_back(i);
        }
        return ans;
    }
};
