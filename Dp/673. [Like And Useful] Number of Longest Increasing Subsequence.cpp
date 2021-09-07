// OK. O(N^2). Intuition. just like classic lis.
// and use addtional array to cache len.
// find max lis length.
// remember to sum all longest length up
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        
        int dp[n];
        int cnt[n];
        
        int mx = 0;
        for(int i = 0; i < n; ++i){
            dp[i] = cnt[i] = 1;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                }
                else if(nums[i] > nums[j] && dp[j]+1 == dp[i]) cnt[i] += cnt[j];
            }
            if(mx < dp[i]) mx = dp[i];
        }
        
        int res = 0;
        for(int i = 0; i < n; ++i) if(mx == dp[i]) res += cnt[i];
        
        return res;
    }
};


// O(NlogN). Patience sorting. 2 binary search + prefix sum. impressive.
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        
        vector<vector<pair<int, int>>> arr(n+1); // like patience sort.

        int max_so_far = 0;
        for(int x: nums){
            // search insert position
            int l = 0, r = max_so_far;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(arr[mid].back().first < x) l = mid+1;
                else r = mid;
            }
            
            // search numbers of way
            int ways = 1;
            int row = l - 1;
            if(row >= 0){
                int l1 = 0, r1 = arr[row].size();
                while(l1 < r1){
                    int mid = l1 + (r1 - l1) / 2;
                    if(arr[row][mid].first < x) r1 = mid;
                    else l1 = mid+1;
                }
                
                ways = arr[row].back().second;
                // impossible, since bigger than x
                ways -= (l1 == 0) ? 0 : arr[row][l1 - 1].second;
            }
            
            // insert arr[l] prefix sum.
            arr[l].push_back({x, arr[l].empty() ? ways: arr[l].back().second + ways});
            if(l == max_so_far) ++max_so_far;
        }
        
        return arr[max_so_far-1].back().second;
    }
};
