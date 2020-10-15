// jump and jump.
// O(N).

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int tmp = nums[0];
        for(int i = 0, jump = i; i < n; ++i){
            int njump = (jump+k)%n;
            int v = nums[njump];
            nums[njump] = tmp;
            jump = njump;
            tmp = v;
        } 
    }
};


// O(N). Reverse
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());;
    }
};
