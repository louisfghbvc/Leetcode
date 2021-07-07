// O(NlogNlogD)

class Solution {
public:
    
    int getK(vector<vector<int>> &mat, int val){
        int n = mat.size();
        int cnt = 0;
        for(auto &r: mat){
            int idx = upper_bound(r.begin(), r.end(), val) - r.begin();
            cnt += idx;
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(getK(matrix, mid) >= k)
                r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};

// O(NlogD). use the matrix sorted property. only go to left
class Solution {
public:
    
    int getK(vector<vector<int>> &mat, int val){
        int n = mat.size();
        int cnt = 0;
        int j = n-1;
        for(int i = 0; i < n; ++i){
            while(j >= 0 && val < mat[i][j]) j--;
            cnt += j+1;
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(getK(matrix, mid) >= k)
                r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};
