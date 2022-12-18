class Solution {
public:
    
    int dis(int x) {
        return log2(x);
    }
    
    vector<int> path(int x) {
        vector<int> res;
        while (x) {
            res.push_back(x);
            x >>= 1;
        }
        return res;
    }
    
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        // goal: find the length of cycle
        // idea: 
        // 1. find the distance -> log(a)
        // ans = distance + 1 = dis[a] + dis[b] - 2*dis[lca] + 1
        // 2. find lca(a, b)
        // find the path from the root, find the common
        // 101 -> 10 -> 1
        // 110 -> 11 -> 1
        
        vector<int> res;
        
        for (auto &q: queries) {
            int a = q[0], b = q[1];
            int ans = dis(a) + dis(b);
            
            vector<int> pa = path(a), pb = path(b);
            int lca = 1;
            unordered_set<int> vis(pb.begin(), pb.end());
            for (int _a: pa) {
                if (vis.count(_a)) { // find lca
                    lca = _a;
                    break;
                }
            }
            
            res.push_back(ans - 2*dis(lca) + 1);
        }
        
        return res;
    }
};


// Solution2, optimized clean
class Solution {
public:
    
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        // goal: find the length of cycle
        // idea: 
        // jump until both reach lca
        
        vector<int> res;
        for (auto &q: queries) {
            int a = q[0], b = q[1];
            int dis = 1; // base
            while (a != b) {
                if (a > b) a >>= 1;
                else b >>= 1;
                dis++;
            }
            res.push_back(dis);
        }
        
        return res;
    }
};
