// O(N). So global is difference > 1.

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int mx = A[0];
        for(int i = 0; i+2 < A.size(); ++i){
            mx = max(mx, A[i]);
            if(mx > A[i+2]) return false;
        }
        return true;
    }
};


// O(NlogN) mergeSort.
class Solution {
public:
    
    vector<int> tmp;
    int mergeSort(vector<int> &A, int l, int r){
        if(l >= r) return 0;
        int mid = (l+r)/2;
        // divide
        int L = mergeSort(A, l, mid);
        int R = mergeSort(A, mid+1, r);
        
        // combine
        int ls = l, rs = mid+1, ts = l;
        int res = 0;
        while(ls <= mid && rs <= r){
            if(A[ls] > A[rs]){
                res += mid-ls+1;
                tmp[ts++] = A[rs++];
            }
            else tmp[ts++] = A[ls++];
        }
        while(ls <= mid) tmp[ts++] = A[ls++];
        while(rs <= r) tmp[ts++] = A[rs++];
        
        for(int i = l; i <= r; ++i)
            A[i] = tmp[i];
        
        return L + R + res;
    }
    
    bool isIdealPermutation(vector<int>& A) {
        int local = 0;
        for(int i = 0; i+1 < A.size(); ++i){
            local += A[i] > A[i+1];
        }
        tmp.resize(A.size());
        int global = mergeSort(A, 0, A.size()-1);
        return local == global;
    }
};775. Global and Local Inversions
