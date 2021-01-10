// Simple O(N).
// X^X = 0. X^0 = X
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res(1, first);
        for(int x: encoded){
            res.push_back(x^first);
            first ^= x;
        }
        return res;
    }
};
