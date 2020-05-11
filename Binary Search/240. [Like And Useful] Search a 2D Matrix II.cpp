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

// Solution2. O(mlogn). care auto can not use. timelimit
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        for(int i = 0; i < m; ++i){
            if(search1D(matrix[i], target)) return 1;
        }
        return 0;
    }
    bool search1D(vector<int> &arr, int target){
        int l = 0, r = arr.size()-1;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(target > arr[mid]) l = mid+1;
            else if(target < arr[mid]) r = mid-1;
            else return 1;
        }
        return 0;
    }
};

// Clean code, auto is bad. slow. because it is big.
// but if you use const and reference. AC.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(const auto& row : matrix){
            int l = 0, r = row.size()-1;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(row[mid] == target) return 1;
                else if(row[mid] < target) l = mid+1;
                else r = mid-1;
            }
        }
        return 0;
    }
};
