// O(N).
// convert number to 10-base. check is mod by 5 or not.

class Solution {
public:
    // mod theory.
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int v = 0;
        for(int x: A){
            v = v*2 + x;
            v %= 5;
            res.push_back(v == 0);
        }
        return res;
    }
};
