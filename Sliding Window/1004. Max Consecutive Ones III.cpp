//60ms 13.8MB
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r, mx = 0;
        for(r = 0; r < A.size(); ++r){
            if(!A[r]) K--;
            while(K < 0 && !A[l++]) K++;
            mx = max(r - l + 1, mx);
        }
        return mx;
    }
};
