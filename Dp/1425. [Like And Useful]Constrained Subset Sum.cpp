// Not optimal. O(NlogN)
// Easy to understand.
// key point1 dp[i] = nums[i] + max(dp[i-1], ..., dp[i-k]) or nums[i];
// key point2 use sliding window to get max. this sol use heap.
// 336ms.
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        multiset<int> window = {0};
        
        for(int i = 0; i < nums.size(); ++i){
            dp[i] = nums[i] + *window.rbegin();
            window.insert(dp[i]);
            if(i >= k) window.erase(window.find(dp[i-k]));
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

// Optimal O(N)
// Use deque
// 144ms.14.2MB
static int p = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 1;
}();
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        deque<int> window = {0};
        
        int mx = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            if(i > k && window[0] == dp[i-k-1])
                window.pop_front();
            dp[i] = max(nums[i], nums[i] + window[0]); // put or not put
            mx = max(dp[i], mx);
            while(!window.empty() && window.back() < dp[i])
                window.pop_back();
            window.push_back(dp[i]);
        }
        
        return mx;
    }
};
