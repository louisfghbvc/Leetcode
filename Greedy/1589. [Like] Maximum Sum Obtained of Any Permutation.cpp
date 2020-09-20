// Array tour. and observe that the max fre pair max val.
// O(NlogN).
class Solution {
public:
    const int mod = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        long mx = 0, n = nums.size();
        vector<int> fre(n+1);
        for(auto& q: requests){
            int l = q[0], r = q[1];
            fre[l]++;
            fre[r+1]--;
        }
        
        int sum = 0;
        vector<int> ans(n);
        for(int i = 0; i < n; ++i){
            sum += fre[i];
            ans[i] = sum;
        }
        
        sort(nums.rbegin(), nums.rend());
        sort(ans.rbegin(), ans.rend());
        
        for(int i = 0; i < n; ++i){
            mx = mx + (ans[i]*nums[i]) % mod;
            mx %= mod;
        }
        
        return mx;
    }
};

// Optimal. fre can just add. O(NlogN).
class Solution {
public:
    const int mod = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        long mx = 0, n = nums.size();
        vector<int> fre(n+1);
        for(auto& q: requests){
            int l = q[0], r = q[1];
            fre[l]++;
            fre[r+1]--;
        }
        
        for(int i = 1; i < n; ++i)
            fre[i] += fre[i-1];
        
        sort(nums.rbegin(), nums.rend());
        sort(fre.rbegin(), fre.rend());
        
        for(int i = 0; i < n; ++i){
            mx = mx + (fre[i]*nums[i]) % mod;
            mx %= mod;
        }
        
        return mx;
    }
};
