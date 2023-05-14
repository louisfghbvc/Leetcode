class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        // goal: find the matrix sum
        // idea: sort each row by val, find col max
        
        for (auto &row: nums)
            sort(row.begin(), row.end());
        
        int m = nums.size();
        int n = nums[0].size();
        
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int col = 0;
            for (int i = 0; i < m; ++i)
                col = max(col, nums[i][j]);
            ans += col;
        }
        
        return ans;
    }
};
