class Solution {
public:
    int maxScore(vector<int>& nums) {
        // goal: find the maximum score
        // score: nubmer of pre[i] > 0
        // idea:
        sort(nums.rbegin(), nums.rend());        
        int cnt = 0;
        long sum = 0;
        for (int x: nums) {
            sum += x;
            cnt += sum > 0; 
        }
        return cnt;
    }
};
