//48ms 13.8MB
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r;
        for(r = 0; r < A.size(); ++r){
            if(!A[r]) K--;
            if(K < 0 && !A[l++]) K++;
        }
        return r - l;
    }
};
