// take largest value. first and just put into bag.

class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int S) {
        sort(box.begin(), box.end(), [&](vector<int>&a, vector<int>&b){
            return a[1] > b[1];
        });
        int res = 0, c = 0;
        for(auto &r: box){
            if(c + r[0] <= S){
                res += r[0] * r[1];
                c += r[0];
            }
            else{
                int rm = S - c;
                res += rm * r[1];
                break;
            }
        }
        return res;
    }
};
