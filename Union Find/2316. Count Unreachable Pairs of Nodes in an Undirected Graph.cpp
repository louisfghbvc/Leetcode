class Solution {
public:
    
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    
    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        p[x] += p[y];
        p[y] = x;
        return true;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        // goal: calculate the number of pairs such that cannot connect to each other
        // idea:
        // union find, found the group size
        // each group
        // 1 2 4
        // 1x6 + 2x5 + 4x3 = 28 
        // divide two
        
        long ans = 0;
        
        p.assign(n, -1);
        for (auto &e: edges)
            uni(e[0], e[1]);
        
        vector<long> groups;
        for (int i = 0; i < n; ++i) {
            if (p[i] < 0)
                groups.push_back(-p[i]);
        }
        
        long total = accumulate(groups.begin(), groups.end(), 0L);
        for (auto& x: groups) {
            ans += x * (total - x);
        }
        
        return ans / 2;
    }
    
private:
    vector<int> p;
};
