// Guess and calculate number of element.
// O(NlogNlogX).

class Solution {
public:
    // 1  5  9
    // 10 11 13
    // 12 13 15
    // guess number and use binary search 
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1]+1;
        
        while(l < r){
            int mid = l + (r-l)/2;
            int cnt = 0;
            for(int i = 0; i < n; ++i){
                int num = upper_bound(matrix[i].begin(), matrix[i].end(), mid) -matrix[i].begin();
                cnt += num;
            }
            if(cnt < k) l = mid+1;
            else r = mid;
        }
        
        return l;
    }
};

// Cuz right part is bigger and bigger.
// O(NlogX).
class Solution {
public:
    // 1  5  9
    // 10 11 13
    // 12 13 15
    // guess number and use binary search
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1]+1;
        
        while(l < r){
            int mid = l + (r-l)/2;
            int cnt = 0, j = n-1;
            for(int i = 0; i < n; ++i){
                while(j >= 0 && matrix[i][j] > mid) j--;
                cnt += j+1;
            }
            if(cnt < k) l = mid+1;
            else r = mid;
        }
        
        return l;
    }
};
