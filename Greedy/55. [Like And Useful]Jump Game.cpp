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

// forward 4ms 7.7MB
// very greedy. I think the same idea, but don't know how to implement.
// from st, try get max step.
//why front index doesn't need to jump? because u step from step,
//u won't jump to back then jump to begin
static int p = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i = 0; i <= x; ++i){
            x = max(x, i+nums[i]);
            if(x >= n-1) return 1;
        }
        return 0;
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
