// use xor
// O(N^2), space O(1)

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n; ++i){
            int row = 0, col = 0;
            for(int j = 0; j < n; ++j){
                col ^= matrix[i][j] ^ (j+1);
                row ^= matrix[j][i] ^ (j+1);
            }
            if(row || col) return false;
        }
        
        return true;
    }
};
