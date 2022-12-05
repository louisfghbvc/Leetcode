class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // goal: find the sum of product of a team
        // all team size is 2, and sum is all the same
        // idea:
        // sort skill, and pair them (arr[i], arr[n-1-i])
        // 1 2 3 3 4 5 
        // ^         ^
        //   ^     ^
        //     ^ ^
        
        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        int sum = skill[0] + skill[n-1];
        
        long ans = 0;
        for (int i = 0; i < n/2; ++i) {
            int cur = skill[i] + skill[n-1-i];
            if (cur != sum) return -1;
            ans += skill[i] * skill[n-1-i];
        }
        
        return ans;
    }
};
