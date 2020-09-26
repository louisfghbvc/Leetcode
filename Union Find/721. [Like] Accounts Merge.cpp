// Union - Find. 3 Pass.
// First, merge email id to i. and duplicate merge to one i.
// Second, find email belong to who. into a hash map.
// hash map to res.

class Solution {
public:
    int p[10005];
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        p[y] = x;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> res;
        memset(p, -1, sizeof p);
        
        unordered_map<string, int> eid;
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                if(!eid.count(accounts[i][j])) eid[accounts[i][j]] = n+eid.size();
                uni(i, eid[accounts[i][j]]);
            }
        }
        
        unordered_map<int, set<string>> person;
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                person[find(eid[accounts[i][j]])].insert(accounts[i][j]);
            }
        }
        
        for(auto &[id, emails]: person){
            vector<string> tmp = {accounts[id][0]};
            tmp.insert(tmp.end(), emails.begin(), emails.end());
            res.emplace_back(tmp);
        }
        
        return res;
    }
};
