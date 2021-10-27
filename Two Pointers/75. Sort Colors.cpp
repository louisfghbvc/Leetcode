// one is zero, other is two, and rest is one.
// O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int two = nums.size()-1, zero = 0;
        for(int i = 0; i <= two; ++i){
            while(nums[i] == 2 && i < two) swap(nums[i], nums[two--]);
            while(nums[i] == 0 && i > zero) swap(nums[i], nums[zero++]);
        }
    }
};


// Counting sort O(N).
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt[3] = {};
        for(int x: nums) cnt[x]++;
        
        int i = 0;
        for(int k = 0; k < 3; ++k){
            while(cnt[k]--) nums[i++] = k;
        }
        
    }
};

// One pass. straight forward.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int zero = 0, two = n - 1;
        for(int i = 0; i <= two; ){
            if(nums[i] == 0){
                swap(nums[zero], nums[i]);
                zero++;
                i++;
            }
            else if(nums[i] == 2){
                swap(nums[two], nums[i]);
                two--;
            }
            else i++;
        }
        
    }
};
