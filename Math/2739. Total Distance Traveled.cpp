class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        // goal: find the distance that traveled
        // idea: math
        
        int ans = 0;
        while (mainTank >= 5) {
            int get = min(mainTank / 5, additionalTank);
            ans += (mainTank / 5) * 50;
            mainTank %= 5;
            mainTank += get;
            additionalTank -= get;
        }
        if (mainTank)
            ans += mainTank * 10;
        return ans;
    }
};
