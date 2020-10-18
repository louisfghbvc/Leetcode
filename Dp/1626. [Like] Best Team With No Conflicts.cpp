// Just like LIS. dp
// sort by age.
// O(N^2). and calculate dp, if score[i] >= score[j]. dp[i] = dp[j]+score[i].

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<vector<int>> arr;
        for(int i = 0; i < n; ++i) arr.push_back({scores[i], ages[i]});
        sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
        });
        
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i){
            dp[i] = arr[i][0];
            for(int j = i-1; j >= 0; --j){
                if(arr[i][0] >= arr[j][0]){
                    dp[i] = max(dp[j] + arr[i][0], dp[i]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
