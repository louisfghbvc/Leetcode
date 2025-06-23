class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        // problem:
        // return a sorted unique integer array
        // a array that means numWay[i] = num of ways can get i
        // (2,4) (4,2) is the same

        // [0,1,0,2,0,3,0,4,0,5]

        // if impossible, return empty
        //  0 0 0 1 0 2 0 3 0 4
        //        4

        // idea:
        // iterate from smallest index
        // we can easily get the value using transition

        // think inverse
        // 2,4,6

        // 0 1 2 3 4 5 6 7 8 9 10
        // 1 0 1 0 2 0 3 0 4 0 5

        // when we find a value we update the dp back
        // in reverse order
        // 0 1 2 3 4 5 6 7 8 9 10
        // 1 0 0 0 1 0 1 0 0 0 0

        int n = numWays.size();
        numWays.insert(numWays.begin(), 1); // base case
        vector<int> res;
        while (true) {
            bool hasOne = false;
            int x = -1;
            for (int i = 1; i <= n; ++i) {
                if (numWays[i] == 1) {
                    hasOne = true;
                    x = i;
                    res.push_back(x);
                    break;
                }
            }
            if (!hasOne) break;

            // update
            for (int i = n; i >= x; --i) {
                numWays[i] -= numWays[i-x];
            }
        }

        // should be all zero
        if (count(numWays.begin(), numWays.end(), 0) == n)
            return res;
        return {};
    }
};

