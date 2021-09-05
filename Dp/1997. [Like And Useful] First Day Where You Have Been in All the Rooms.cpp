// Only understand odd even dp.
// O(N). like graph, transition.

class Solution {
public:
    const int mod = 1e9+7;

    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long> dp(n); // dp[i]: finish days, odd times vis i
        vector<long> dp2(n); // dp2[i]: finish days, even times vis i
        dp2[0] = 1;
        
        for(int i = 1; i < n; ++i){
            // odd
            dp[i] = (dp2[i-1] + 1) % mod;

            // even
            long day = dp[i] - dp[nextVisit[i]]; // need odd i - odd nextVisited[i](previous). 
            if(day < mod) day += mod;
            dp2[i] = (dp[i] + 1 + day) % mod;
        }
        
        return dp.back();        
    }
};
