// O(NlogN). O(N)

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // idea: use union-find to merge the pairs
        // each group just sort them
        int n = s.size();
        p = vector<int>(n, -1);
        
        // merge the group
        for (auto &edge: pairs) {
            uni(edge[0], edge[1]);
        }
        
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> mp; // root id -> min heap
        for (int i = 0; i < n; ++i) {
            mp[find(i)].push(s[i]);
        }
        
        string res;
        for (int i = 0; i < n; ++i) {
            res += mp[find(i)].top();
            mp[find(i)].pop();
        }
        
        return res;
    }
    
private:
    vector<int> p;
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }
};
