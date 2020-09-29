// think it as bfs. shortest path problem. O(N).
// say 2 3 1 1 4.
// level 0: 2
// level 1: 3 1
// level 2: 1 4.

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0, start = 0, cur = 0, next = 0;
        while(start < n-1){
            step++;
            for(; start <= cur; ++start){
                if(start + nums[start] >= n-1) return step;
                next = max(next, start + nums[start]);
            }
            cur = next;
        }
        return step;
    }
};
