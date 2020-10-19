// Simple enum all 1~6
// O(N).
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans = 1e9;
        int n = A.size();
        bool ok = 0;
        for(int d = 1; d <= 6; ++d){
            int sum1 = 0, sum2 = 0;
            bool allA = 1, allB = 1;
            for(int i = 0; i < n && allA; ++i){
                if(A[i] != d){
                    if(B[i] != d) allA = 0;
                    else sum1++;
                } 
            }
            for(int i = 0; i < n && allB; ++i){
                if(B[i] != d){
                    if(A[i] != d) allB = 0;
                    else sum2++;
                } 
            }
            if(allA) ans = min(ans, sum1), ok = 1;
            if(allB) ans = min(ans, sum2), ok = 1;
        }
        return ok ? ans : -1;
    }
};

// Solution2. use extra space cnt array to cnt each and same.
