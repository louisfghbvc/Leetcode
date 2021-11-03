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


// Union find, tricky, path compression and value union tricky

class Solution {
public:
    
    string find(string& a){
        if(!parent.count(a)){
            val[a] = 1.0;
            return parent[a] = a;
        }
        string pa = parent[a];
        if(pa == a) return a;
        string root = find(pa);
        val[a] *= val[pa];
        return parent[a] = root;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // e0 / e1 = v[i]
        // e0 = val[e0] * r1
        // e1 = val[e1] * r2
        
        // build graph
        for(int i = 0; i < equations.size(); ++i){
            // union
            auto r0 = find(equations[i][0]), r1 = find(equations[i][1]);
            parent[r0] = r1;
            val[r0] = val[equations[i][1]] * values[i] / val[equations[i][0]];
        }
        
        vector<double> ret;
        
        // each is O(1)
        for(auto &q: queries){
            if(!parent.count(q[0]) || !parent.count(q[1])){
                ret.push_back(-1);
                continue;
            }
            if(find(q[0]) != find(q[1])){
                ret.push_back(-1);
                continue;
            }
            ret.push_back(val[q[0]] / val[q[1]]);
        }
        return ret;
    }
private:
    unordered_map<string, string> parent;
    unordered_map<string, double> val;
};
