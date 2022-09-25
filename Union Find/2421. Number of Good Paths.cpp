class Solution {
public:
    
    int add(int n) { // 2+1
        return (1+n)*n/2;
    }
    
    vector<int> p;
    vector<pair<int, int>> group; // maximum value and size
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (group[y].first == group[x].first) {
            group[x].second += group[y].second;
        }
        else {
            if (group[y].first > group[x].first)
                group[x] = group[y];
        }
        p[y] = x;
    }
    
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // goal: find the number of distinct good paths 
        // such that the start and end node has the same value
        // and the path between these value is smaller than node
        
        // idea2: from smallest to greatest
        // union the edge
        
        int n = vals.size();
        p = vector<int>(n, -1);
        for (int i = 0; i < n; ++i)
            group.push_back({vals[i], 1});
        
        auto get_max = [&](vector<int> &e) {
            return max(vals[e[0]], vals[e[1]]);
        };
        
        sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
            return get_max(a) < get_max(b);
        });
        
        set<int> distinct(vals.begin(), vals.end());
        unordered_map<int, vector<int>> mp; // value -> index
        for (int i = 0; i < n; ++i) 
            mp[vals[i]].push_back(i);
        
        int ans = 0;
        int i = 0, m = edges.size();
        for (int x: distinct) {
            // union
            while (i < m && get_max(edges[i]) == x) {
                uni(edges[i][0], edges[i][1]);
                i++;
            }
            unordered_set<int> root;
            for (int idx: mp[x])
                root.insert(find(idx));
            for (int idx: root)
                ans += add(group[idx].second);
        }
        
        return ans;
    }
};
