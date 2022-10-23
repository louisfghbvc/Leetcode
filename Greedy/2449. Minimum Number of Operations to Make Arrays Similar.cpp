class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        // goal: find the minimum operations such that nums == target, each value frequency is the same
        // idea: ?
        // observe1: the order we don't consider 
        // observe2: target minimum always -> pair one
        
        // nums = 6,8,12, target = 2,10,14
        //       -4,+2,+2
        //.      +4, -4, +2, -2
        //          
        // nums = [2] [1,5], target = [1, 3], [4]
        //         +2  0 -2
        // 
        
        // idea1: sort them, compare one by one -> fail
        // same odd, even will consider one by one
        // 
        
        priority_queue<int, vector<int>, greater<>> heap[2]; // 0: even, 1: odd
        for (int x: target)
            heap[x&1].push(x);
        sort(nums.begin(), nums.end());
        
        long ans = 0;
        for (int x: nums) {
            int target_x = heap[x&1].top(); heap[x&1].pop();
            if (x == target_x) continue;
            if (x > target_x) {
                long diff = x - target_x; // need decrease
                ans += diff;
            }
            else {
                long diff = target_x - x; // need increase
                ans += diff;
            }
        }
        return ans/4;
    }
};
