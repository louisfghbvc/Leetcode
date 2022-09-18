class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // goal: return the n-array, where each is the smallset length of maximum OR

        // observe: 
        // if current index is maximum no need to going to the right
        // seperate each bit, find the smallest one, in the right
        // each index, get all bit smallest right
        
        
        // [01,00,10,01,11], maximum OR = 3
        //  
        // right = {2, max(1, 4), max(), ....}
        
        
        int n = nums.size();
        
        vector<int> right(n);
        
        for (int i = 0; i < 31; ++i) {
            int last = -1;
            for (int j = n-1; j >= 0; --j) {
                if (nums[j] >> i & 1) { // have ith bit, setting the last index
                    last = j;
                }
                right[j] = max(right[j], last);
            }
        }
        
        for (int i = 0; i < n; ++i)
            right[i] = max(right[i]-i+1, 1);
        return right;
    }
};
