// O(N).
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> ind(n);
        for(auto &e: edges){
            ind[e[0]-1]++;
            ind[e[1]-1]++;
        }
        for(int i = 0; i < n; ++i){
            if(ind[i] == n-1) return i+1;
        }
        return -1;
    }
};

// O(1), just check begin and end. since the center must appear.
