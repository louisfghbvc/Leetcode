// O(N). observe that just compare the left mx, right mn.

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> mn(n);
        
        mn.back() = nums[n-1];
        for(int i = n-2; i >= 0; --i)
            mn[i] = min(nums[i], mn[i+1]);
        
        int mx = 0;
        for(int i = 0; i+1 < n; ++i){
            mx = max(nums[i], mx);
            if(mx <= mn[i+1])
                return i+1;
        }
        
        return 0;
    }
};
