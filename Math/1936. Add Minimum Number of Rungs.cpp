// O(N). Why - 1? since we don't take edge points. [0 4], 1. only add 3.

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        
        int prev = 0;
        int cnt = 0;
        for(int x: rungs){
            int dif = x - prev - 1;
            if(dif >= dist){
                cnt += dif / dist;
            }
            prev = x;
        }
        return cnt;
    }
};
