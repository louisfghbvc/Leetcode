// Just think about only 2 stones.
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        sort(milestones.begin(), milestones.end());
        
        int n = milestones.size();
        long tot = 0;
        for(int i = 0; i < n - 1; ++i){
            tot += milestones[i];
        }
        if(tot >= milestones[n-1]){
            return tot + milestones[n-1];
        }
        return tot * 2L + 1L;
    }
};
