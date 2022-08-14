class Solution {
public:
    int edgeScore(vector<int>& edges) {
        // goal: calculate the indegree, find maximum indegree
        // idea: calculate the score sum
        
        // TC: O(N), SC: O(N)
        
        int n = edges.size();
        
        vector<long> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[edges[i]] += i;
        }
        
        long mx = *max_element(ind.begin(), ind.end());
        
        for (int i = 0; i < n; ++i) {
            if (ind[i] == mx) return i;
        }
        
        return -1;
    }
};
