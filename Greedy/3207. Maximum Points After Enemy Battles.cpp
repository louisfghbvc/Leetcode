class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        // goal: find the maximum points
        // each time we can do 2 operations 
        // 1. kill one enemy, cur energy >= enemy[i], i is not mark
        // 2. get no points, we have at least one point, choose unmark enemy, then mark, and add
        // 
        
        //      kill
        // [3,2,2]
        //  
        
        // idea:
        // order is no matter
        // first operation: we can get 1 point if any one is smaller
        // [3,2,2], 2, 0
        //  3 2 2.  0  1
        //. 3 2 x   0, 2 
        //. 
        
        // 1. sort the array
        // 2. kill the smallest person, do operation1
        // 3. marked the largest one, kill all others
        
        ranges::sort(enemyEnergies);
        if (currentEnergy < enemyEnergies[0]) {
            return 0;
        }
        
        currentEnergy -= enemyEnergies[0];
        long sum = currentEnergy;
        for (int i = 1; i < enemyEnergies.size(); ++i) {
            sum += enemyEnergies[i];
        }   
        return 1 + sum / enemyEnergies[0];
    }
};
