class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // goal: maximum the sum of matrix such that we can choose adjacent elements
        // multiply each of them by -1

        // idea:
        // [-x  -x]
        // [x  x] 

        // [-x] y 
        // [-x] y

        // think the dp
        // dp[i][j][1]: ending at (i,j) maximum we can get, flip or not
        // consider (i,j) flip or not
        // dp not work

        // idea2: looks constructive
        // any two negative one can always erase it.
        // when we flip we can make negative move to any position
        // [-1] [1]
        // [ 1] [-1] => flip both -1 
        //  1 1 1
        //  1 -1 1
        //  1 1 -1 

        int n = matrix.size();
        int neg = 0;
        int mn = INT_MAX;
        long sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                neg += matrix[i][j] < 0;
                mn = min(mn, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        
        // odd
        if (neg % 2) {
            return sum - 2*mn;
        }
        else {
            return sum;
        }
    }
};
