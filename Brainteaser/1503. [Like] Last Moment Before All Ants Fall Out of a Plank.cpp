// The ants keep walking, it is uva question.

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for(auto &x: left){
            res = max(res, x);
        }
        for(auto &x: right){
            res = max(n-x, res);
        }
        return res;
    }
};
