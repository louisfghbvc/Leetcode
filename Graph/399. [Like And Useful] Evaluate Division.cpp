// Wow, think it as graph. so when some relation. just think as graph. edge.
// and dfs. if cycles says false. so res = -1.
// and backtrack the possible.

class Solution {
public:
    unordered_map<string, vector<pair<string, double>> > g;
    unordered_set<string> vis;
    bool dfs(string u, string &ed, double &res){
        if(!g.count(u)) return false;
        if(u == ed) return true;
        vis.insert(u);
        for(auto &[v, val]: g[u]){
            if(!vis.count(v)){
                res *= val;
                if(dfs(v, ed, res)) return true;
                res /= val;
            }
        }
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < values.size(); ++i){
            vector<string> &e = equations[i];
            g[e[0]].push_back({e[1], values[i]});
            g[e[1]].push_back({e[0], 1.0/values[i]});
        }
        
        vector<double> res;
        for(auto &q: queries){
            vis.clear();
            double tmp = 1.0;
            if(dfs(q[0], q[1], tmp))
                res.push_back(tmp);
            else res.push_back(-1);
        }
        
        return res;
    }
};
