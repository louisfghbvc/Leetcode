// One pass use two param.
// O(N).
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool inc = 1, dec = 1;
        for(int i = 0; i < n-1; ++i){
            if(A[i] > A[i+1]) inc = 0;
            if(A[i] < A[i+1]) dec = 0;
        }
        return inc || dec;
    }
};

// two pass.
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool ok = 1;
        for(int i = 0; i < n-1; ++i){
            if(A[i] > A[i+1]){
                ok = 0; break;
            }
        }
        if(ok) return 1;
        ok = 1;
        for(int i = 0; i < n-1; ++i){
            if(A[i] < A[i+1]){
               ok = 0; break;
            }
        }
        return ok;
    }
};
