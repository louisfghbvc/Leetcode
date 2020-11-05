// O(N). just check the parity.
// when odd to even or even to odd. have cost.

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int f[2] = {};
        for(int x: position) f[x%2]++;
        return min(f[0], f[1]);
    }
};
