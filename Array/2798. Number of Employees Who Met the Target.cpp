class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        // goal: find the number of employee work hours[i] >= target   
        
        // [2,1,3], target=1, ans = 3;
        
        int cnt = 0;
        for (int x: hours)
            cnt += x >= target;
        return cnt;
    }
};
