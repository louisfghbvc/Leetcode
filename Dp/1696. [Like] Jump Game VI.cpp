// Cause it need to find largest. so that can not use bfs.
// do a dp, dp[r] is from [r-k, r).
// O(NlogN). can reduce to O(N). since use maximum deque.
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -1e9);
        dp[0] = nums[0];
        
        multiset<int> st;
        st.insert(dp[0]);
        
        for(int r = 1, l = 0; r < n; ++r){
            if(r - k > 0){
                st.erase(st.find(dp[r-k-1]));
            }
            dp[r] = *st.rbegin() + nums[r];
            st.insert(dp[r]);
        }
        
        return dp.back();
    }
};

// Monotonous Queue + dp. O(N).
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -1e9);
        dp[0] = nums[0];
        
        deque<int> dq;
        dq.push_back(0);
        
        for(int r = 1; r < n; ++r){
            if(dq.size() && r - dq.front() > k) dq.pop_front();
            dp[r] = dp[dq.front()] + nums[r];
            
            while(dq.size() && dp[dq.back()] < dp[r]) dq.pop_back();
            dq.push_back(r);
        }
        
        return dp.back();
    }
};
