// O(1). Optimal solution.
// from big to small. check time is valid
// just a boring problem.

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        char res[7];
        sort(A.rbegin(), A.rend());
        do{
            int h = A[0]*10+A[1], m = A[2]*10+A[3];
            if(h >= 24 || m >= 60) continue;
            sprintf(res, "%02d:%02d", h, m);
            return res;
        }while(prev_permutation(A.begin(), A.end()));
        return "";
    }
};
