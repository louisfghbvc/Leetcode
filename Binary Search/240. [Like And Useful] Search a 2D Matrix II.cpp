// Solution1. Optimal linear. O(m+n)
// u can see the matrix as binary search tree. from top right. each node has two root.
// because row ascending, col ascending. 
// trick solution.
// [1,   4,  7, 11, 15],
// [2,   5,  8, 12, 19],
// [3,   6,  9, 16, 22],
// [10, 13, 14, 17, 24],
// [18, 21, 23, 26, 30]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        int r = 0, c = n-1;
        while(r < m && c >= 0){
            if(target > matrix[r][c]) r++;
            else if(target < matrix[r][c]) c--;
            else return 1;
        }
        return 0;
    }
};

// Solution2. Divide And Conquer. hard code.
// into 4 sub. 
// not implement yet.
