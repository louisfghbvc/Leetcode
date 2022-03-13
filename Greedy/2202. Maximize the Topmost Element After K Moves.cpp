// T: O(N), S: O(1),


class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        // goal: maximum nums[0]
        // op1: remove topmost
        // op2: add remove to topmost
        
        // n = 1, k is odd
        if(nums.size() == 1){
            if(k % 2)
                return -1;
            return nums[0];
        }
        
        // n >= 2, k > n -> maximum
        if(nums.size() >= 2 && k > nums.size()) 
            return *max_element(nums.begin(), nums.end()); 
        
        // n >= 2, k <= n
        // two case
        // 1. erase k element
        // 2. erase k-1 element, add one maximum
        int first = k == nums.size() ? INT_MIN : nums[k];
        int second = k <= 1 ? INT_MIN : *max_element(nums.begin(), nums.begin()+k-1);
        return max(first, second);
    }
};
