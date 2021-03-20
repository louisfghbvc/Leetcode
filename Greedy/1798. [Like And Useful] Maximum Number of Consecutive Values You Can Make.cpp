// So trick. O(NlogN).
// if u can made 1 ~ res-1. this number you can made from 1 ~ res - 1 + num[i].

class Solution {
public:
    
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int res = 1;
        for(int i = 0; i < coins.size() && coins[i] <= res; ++i)
            res += coins[i];
        return res;
    }
};
