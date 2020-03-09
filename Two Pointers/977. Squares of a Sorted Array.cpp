//88ms - 96ms, 12.4MB
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size(), 0);
        for(int l = 0, r = A.size() - 1, id = A.size() - 1; l <= r;){
            if(A[l]*A[l] > A[r]*A[r])
                ans[id--] = A[l]*A[l++];
            else
                ans[id--] = A[r]*A[r--];
        }
        return ans;
    }
};
