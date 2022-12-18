class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        // goal: add at most two edges to make graph degree all even
        // idea: 
        // build the graph, and enumerate the case
        // only 0, 2, 4 odd points case
        
        vector<int> ind(n);
        vector<unordered_set<int>> graph(n); 
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            u--, v--;
            ind[u]++, ind[v]++;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        vector<int> odd;
        for (int i = 0; i < n; ++i)
            if (ind[i] & 1)
                odd.push_back(i);
        
        if (odd.size() == 2) {
            int a = odd[0], b = odd[1];
            for (int i = 0; i < n; ++i)
                if (!graph[a].count(i) && !graph[b].count(i))
                    return true;
            return !graph[a].count(b);
        }
        else if(odd.size() == 4) {
            int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
            if (!graph[a].count(b) && !graph[c].count(d))
                return true;
            if (!graph[a].count(c) && !graph[b].count(d))
                return true;
            if (!graph[a].count(d) && !graph[b].count(c))
                return true;
        }
        
        return odd.size() == 0;
    }
};
