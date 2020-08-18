// Very hard to think. try all case, and from 4 to 3 to 2 to 1.
// backward 2 merge to 1. very fun.
// O(1).
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        return judge24(vector<double>(nums.begin(), nums.end()));
    }
    bool judge24(vector<double> nums){
        int n = nums.size();
        if(n == 1) return abs(nums[0] - 24) < 1e-8;
        sort(nums.begin(), nums.end());
        do{
            vector<double> tmp(nums.begin(), nums.end()-1);
            double a = nums[n-1], b = nums[n-2];
            for(auto x: {a+b, a-b, a*b, b?a/b:0}){
                tmp.back() = x;
                if(judge24(tmp)) return true;
            }
        }while(next_permutation(nums.begin(), nums.end()));
        
        return false;
    }
};
