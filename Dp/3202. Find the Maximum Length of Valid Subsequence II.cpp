// if hard to using index as dp
// think about using value as dp
// Why no next dp? since each mod value will only used in once!!!

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // goal: find the maximum legnth
        // idea: dp
        // consider current index i
        // dp[arr[i]][m] : ending with current index i, we have arr[i], where the mod of subsequence is m

        vector dp(k, vector(k, 0));
        int ans = 0;
        for (int x: nums) {
            x %= k;
            for (int m = 0; m < k; ++m) {
                int prev = ((m - x) % k + k) % k;
                dp[x][m] = max(dp[x][m], dp[prev][m] + 1);
                ans = max(ans, dp[x][m]);
            }
        }

        return ans;
    }
};

// Enumerate the mod value, find out the maximum subsequence
// 
class Solution {
public:
    
    int helper(vector<int>& nums, int k, int sum) {
        int n = nums.size();
        vector<int> next(n, -1);
        vector<int> last(k, -1);
        for (int i = n-1; i >= 0; --i) {
            int val = ((sum - nums[i]) % k + k) % k;
            if (last[val] != -1) 
                next[i] = last[val];
            last[nums[i]] = i;
        }
        
        int ans = 0;
        vector<int> vis(n, false);
        for (int i = 0; i < n; ++i) if (!vis[i]) {
            int len = 1;
            int j = i;
            while (!vis[j] && next[j] != -1) {
                vis[j] = true;
                len++;
                j = next[j];
            }
            vis[j] = true;
            ans = max(ans, len);
        }
        return ans;
    }
    
    int maximumLength(vector<int>& nums, int k) {
        // goal: find the maximum length that subsequence, each (sub[i]+sub[i+1]) % k is the same
        // idea:
        // (sub[i]+sub[i+1]) % k = (sub[i+1]+sub[i+2]) % k
        // sub[i] % k = sub[i+2] % k
        // sub[i+1] % k = sub[i+3] % k
        // all odd index should be the same
        // all even index should be the same
        
        // [1,4,2,3,1,4], k = 3
        //  1 1 2 0 1 1 
        // dp[i][x][y], starting from index i, we have odd mod is x, even mod is y
        // each index we can skip or not
        // dfs(i, x, y, usedX) 
        // skip index i : dfs(i+1, x, y, usedX) 
        // use index i :
        // if (usedX) -> check if can equal to x
        // if (usedX == false) -> check if can equal to y
        // TC: O(n^3)
        
        // improve:
        // look it together
        // enumerate the x+y value = sum
        // (sub[i]+sub[i+1]) % k = sum
        // 1 1 2 0 1 1, if sum = 2 find out the next value that make sum 
        // 1
        // build the next array such that arr[i]+next[i] = sum
        // we can used for loop to traverse the seq
        
        for (auto &x: nums)
            x %= k;
        
        int ans = 0;
        for (int sum = 0; sum < k; ++sum) {
            ans = max(ans, helper(nums, k, sum));
        }
        return ans;
    }   
};
