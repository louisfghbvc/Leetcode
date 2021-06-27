// Just from small. O(NlogN).
class Solution {
public:
    typedef pair<int, int> ii;
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n);
        
        priority_queue<ii, vector<ii>, greater<>> pq;
        for(int i = 0; i < n; ++i){
            pq.push({ratings[i], i});
        }
        
        while(pq.size()){
            auto [rate, idx] = pq.top(); pq.pop();
            dp[idx] = 1;
            if(idx && rate > ratings[idx-1]){
                dp[idx] = max(dp[idx-1]+1, dp[idx]);
            }
            if(idx+1 < n && rate > ratings[idx+1]){
                dp[idx] = max(dp[idx+1]+1, dp[idx]);
            }
        }
        
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

// O(N). Two pass. O(N). lazy process
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                dp[i] = max(dp[i], dp[i-1]+1);
            }
        }
        for(int i = n-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                dp[i] = max(dp[i], dp[i+1]+1);
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
