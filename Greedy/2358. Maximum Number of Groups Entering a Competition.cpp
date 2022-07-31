class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        // goal: find the maximum group
        // such that each group size is strictly increasing
        // and the sum of grade is also strictly increasing
        
        // idea: sort them
        // and make group like this
        // 1, 2, 3 .... 
        
        // time: O(sqrt(N)),
        // binary search -> O(logN)
        
        // 6, 1+2+3+4
        // 2, 1+2
        
        int groups = 0;
        int sumG = 0;
        while (sumG <= grades.size()) {
            sumG += ++groups;
        }
        
        return groups-1;
    }
};
