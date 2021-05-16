class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < 1<<n; ++i){
            int loc = 0;
            for(int j = 0; j < n; ++j){
                if(i>>j&1) loc ^= nums[j];
            }
            res += loc;
        }
        return res;
    }
};
