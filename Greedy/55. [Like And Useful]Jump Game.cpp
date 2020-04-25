//Super fast, O(N). One pass,
//just check this index can jump >= last .
//last = this index, ... from back to begin
static int p = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int x = nums.size()-1;
        
        for(int i = nums.size() - 2; i >= 0; --i){
            if(i + nums[i] >= x){
                x = i;
            }    
        }
        
        return x == 0;
    }
};

// dp. bottom-up, from back, 784ms 8.1MB
static int p = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        
        for(int i = n - 2; i >= 0; --i){
            int farj = min(i+nums[i], n-1);
            for(int j = i+1; j <= farj; ++j){
                if(dp[j] == 1){
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[0] == 1;
    }
};
