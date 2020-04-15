//O(N). Space(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 1);
        int R = 1;
        for(int i = 1; i < len; ++i){
            ans[i] = nums[i-1]*ans[i-1];
        }
        for(int i = len-1; i >= 0; --i){
            ans[i] = ans[i] * R;
            R *= nums[i];
        }
        return ans;
    }
};

//O(N). prefix + suffix O(N) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 0);
        vector<int> L(len, 1);
        vector<int> R(len, 1);
        for(int i = 1; i < len; ++i){
            L[i] = L[i-1]*nums[i-1];
        }
        for(int i = len-1; i >= 1; --i){
            R[i-1] = R[i]*nums[i];
        }
        for(int i = 0; i < len; ++i)
            ans[i] = L[i]*R[i];
        return ans;
    }
};
