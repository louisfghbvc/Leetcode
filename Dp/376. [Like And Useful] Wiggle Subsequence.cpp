// Dp magic. just compare adjacent.
// O(N). Space O(1). From Space O(N) to O(1)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int up = 1, down = 1;
        for(int i = 1; i < n; ++i){
            if(nums[i] > nums[i-1]) up = max(up, down+1);
            else if(nums[i] < nums[i-1]) down = max(down, up+1);
        }
        return max(up, down);
    }
};

// maintain two dp. up and down.
// each is choose or not choose. O(N).
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        up, down = [1] * n, [1] * n
        
        for i in range(1, n):
            # not choose nums[i]
            up[i], down[i] = up[i-1], down[i-1]
            
            # choose nums[i]
            if nums[i-1] < nums[i]: # up
                up[i] = max(up[i], down[i-1] + 1)
            elif nums[i-1] > nums[i]: # down
                down[i] = max(down[i], up[i-1] + 1)
        
        return max(up[-1], down[-1])
