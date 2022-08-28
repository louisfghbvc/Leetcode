class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // goal: build a kxk matrix
        // rowCondition
        // 1<2
        // 3<2
        
        // colCondition
        // 3<2<1
        
        // idea: build the graph, do topology
        
        vector<int> row(k+1, -1), col(k+1, -1); // row[k]: k in which row
        
        { // row
            vector<vector<int>> graph(k+1);
            vector<int> ind(k+1);
            for (auto &e: rowConditions) {
                ind[e[0]]++;
                graph[e[1]].push_back(e[0]);
            }
            queue<int> q;
            for (int i = 1; i <= k; ++i)
                if (ind[i] == 0)
                    q.push(i);

            int row_id = k-1; // last row
            while (q.size()) {
                int u = q.front(); q.pop();
                row[u] = row_id--;
                for (int v: graph[u]) {
                    if (--ind[v] == 0) {
                        q.push(v);
                    }
                }
            }
            
            if (count(row.begin()+1, row.end(), -1)) return {}; // any non visited
        }
        { // col
            vector<vector<int>> graph(k+1);
            vector<int> ind(k+1);
            for (auto &e: colConditions) {
                ind[e[0]]++;
                graph[e[1]].push_back(e[0]);
            }
            queue<int> q;
            for (int i = 1; i <= k; ++i)
                if (ind[i] == 0)
                    q.push(i);

            int col_id = k-1; // last row
            while (q.size()) {
                int u = q.front(); q.pop();
                col[u] = col_id--;
                for (int v: graph[u]) {
                    if (--ind[v] == 0) {
                        q.push(v);
                    }
                }
            }
            
            if (count(col.begin()+1, col.end(), -1)) return {}; // any non visited
        }
        
        
        
        vector res(k, vector<int>(k));
        for (int i = 1; i <= k; ++i)
            res[row[i]][col[i]] = i;
        
        return res;
    }
};
