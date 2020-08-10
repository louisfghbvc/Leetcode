// Just Simulate.
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        for(auto &r: A){
            reverse(r.begin(), r.end());
        }
        for(auto &r: A)
            for(auto &c: r)
                c ^= 1; 
        return A;
    }
};
