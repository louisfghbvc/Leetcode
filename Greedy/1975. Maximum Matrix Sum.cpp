// Just count neg count, and two case.
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int num = 0;
        long sum = 0;
        int mn = abs(matrix[0][0]);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                num += matrix[i][j] < 0; 
                sum += abs(matrix[i][j]);
                mn = min(mn, abs(matrix[i][j]));
            }
        }
        return num & 1 ? sum - 2*mn : sum;
    }
};
