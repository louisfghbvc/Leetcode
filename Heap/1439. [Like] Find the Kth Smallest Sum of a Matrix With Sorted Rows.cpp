// Solution1. 
// Very Easy Solution. Just each row add. and maintain size k.
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row = mat[0];
        int m = mat.size(), n = mat[0].size();
        for(int i = 1; i < mat.size(); ++i){
            vector<int> next_row;
            for(int j = 0; j < n; ++j){
                for(auto x: row){
                    next_row.push_back(x + mat[i][j]);
                }
            }
            sort(next_row.begin(), next_row.end());
            next_row.resize(min(k, (int)next_row.size()));
            row = next_row;
        }
        return row[k-1];
    }
};

// Solution 2. Priority_queue.
