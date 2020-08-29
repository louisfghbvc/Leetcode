// O(N^2). Like bubble sort

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        int n = A.size();
        for(int i = n; i >= 1; --i){
            int k = 0;
            for(; k < n && A[k] != i; ++k);
            if(k){
                res.push_back(k+1);
                reverse(A.begin(), A.begin()+k+1);
            }
            if(A[i-1] != i){
                res.push_back(i);
                reverse(A.begin(), A.begin()+i);
            }
        }
        return res;
    }
};
