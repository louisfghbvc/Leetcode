// Sort and Greedy take. so first you can not pick largest.
// and the smallest can put to C. so that next time u can get 4rd biggest.

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend());
        int n = piles.size();
        int res = 0;
        for(int i = 1, j = n-1; i < j; i+=2, j--){
            res += piles[i];
        }
        return res;
    }
};
