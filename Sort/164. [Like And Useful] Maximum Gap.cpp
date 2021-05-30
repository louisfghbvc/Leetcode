// O(NlogN).
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i+1 < nums.size(); ++i)
            res = max(res, nums[i+1] - nums[i]);
        return res;
    }
};

// O(8N). Radix Sort.
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
    
        vector<int> tmp = nums;
        
        int n = nums.size();
        long e = 1;
        // each round look 4 bits
        for(int i = 0; i < 8; ++i){
            vector<int> cnt(16);
            for(int x: nums) 
                cnt[x / e % 16]++;
    
            for(int k = 1; k < 16; ++k) 
                cnt[k] += cnt[k-1];
            
            for(int j = n-1; j >= 0; --j)
                tmp[--cnt[nums[j] / e % 16]] = nums[j];
            
            e <<= 4;
            nums = tmp;
        }
        
        int res = 0;
        for(int i = 1; i < n; ++i)
            res = max(res, nums[i] - nums[i-1]);
        return res;
    }
};

// Bucket Sort. 
