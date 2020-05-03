// Solution1. 
// Very Easy Solution. Just each row add. and maintain size k.
// O(N*M*Klog(MK))
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

// Solution 2. Same, Better type, same time complexity, faster
// O(N*M*Klog(MK)), 548ms
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans(1);
        
        for(int i = 0; i < m; ++i){
            vector<int> next;
            for(int j = 0; j < k && j < ans.size(); ++j){
                for(int l = 0; l < n; ++l){
                    next.push_back(ans[j]+mat[i][l]);
                }
            }
            sort(next.begin(), next.end());
            ans = next;
        }
        return ans[k-1];
    }
};
