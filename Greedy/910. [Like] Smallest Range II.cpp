// Case thinking. very logic.
// Assume, initial ans = max - min. 
// And here. let A[i] < A[j]. and why (A[i] + K, A[j] - K) ?
// say this state is (up, down). always better than this state (A[i] - K, A[j] + K) => (this make range more. no need)
// and update max min, u can do this max = {A.back() - K, A[i] + K, A[i+1] - K}. but A[i+1] - K is covered by (max - K)
// same as min.
// O(NlogN).

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        
        int mx = A.back(), mn = A[0];
        int res = mx - mn;
        for(int i = 0; i+1 < A.size(); ++i){
            mx = max(A.back() - K, A[i] + K);
            mn = min(A[0] + K, A[i+1] - K);
            res = min(res, mx - mn);
        }
        
        return res;
    }
};
