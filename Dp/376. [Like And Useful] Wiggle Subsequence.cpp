// Dp magic. just compare adjacent.
// O(N). Space O(1).
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


// LIS tweak. but only consider two case, neg and positive.
// O(N)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> dif(n-1);
        for(int i = 1; i < n; ++i) dif[i-1] = nums[i] - nums[i-1];
        
        int pos = 0, neg = 0;
        for(int i = 0; i < n-1; ++i){
            if(dif[i] > 0){
                pos = max(pos, neg+1);
            }
            if(dif[i] < 0){
                neg = max(neg, pos+1);
            }
        }
        
        return max(pos, neg) + 1;
    }
};
