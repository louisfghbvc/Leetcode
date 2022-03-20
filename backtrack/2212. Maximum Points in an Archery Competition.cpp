class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        // idea: enumerate the sections that can get
        // a bitmask, for each, try to win alice, sum it up to check the numArrows <= numArrows
        
        vector<int> bob(12);
        int maxScore = 0;
        
        for (int mask = 0; mask < 1<<12; ++mask) {
            int sum = 0;
            int scores = 0;
            vector<int> tmp(12);
            
            for (int i = 0; i < 12; ++i) {
                if (mask >> i & 1) { // section i
                    scores += i;
                    sum += aliceArrows[i]+1;
                    tmp[i] = aliceArrows[i]+1;
                }
            }
            
            if (sum <= numArrows && scores > maxScore) {
                maxScore = scores;
                bob = tmp;
            }
            
        }
        
        // a edge case
        int sum = accumulate(bob.begin(), bob.end(), 0);
        int need = numArrows - sum;
        bob[0] += need;
      
        return bob;
    }
};
