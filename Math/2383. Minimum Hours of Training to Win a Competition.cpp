class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        // goal: find the minimum hours to defeats all opponent
        // idea: simulate it, do from left to right
        
        int n = energy.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int training = max(energy[i] - initialEnergy + 1, 0);
            int training1 = max(experience[i] - initialExperience + 1, 0);
            res += training + training1;
            initialEnergy += training;
            initialEnergy -= energy[i];
            initialExperience += experience[i] + training1;
        }
        
        return res;
    }
};
