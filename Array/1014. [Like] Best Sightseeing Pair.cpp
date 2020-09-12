// TLE, O(N^2). BF

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        int mx = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i-1; j >= 0; --j){
                int score = A[i]+A[j] + j-i;
                mx = max(mx, score);
            }
        }
        return mx;
    }
};


// look about the second for loop. duplicate right?.
// A[j]+j is duplicate. because A[i]-i is not change, only change A[j]+j. so just get max A[j]+j.
// O(N).
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        int mx = 0, lmx = 0;
        for(int i = 0; i < n; ++i){
            // lmx = max of A[j]+j
            int score = A[i] - i + lmx;
            mx = max(mx, score);
            lmx = max(lmx, A[i]+i);
        }
        return mx;
    }
};
