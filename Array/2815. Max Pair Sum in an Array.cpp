class Solution {
public:
    
    int maxDigit(int x) {
        int mx = 0;
        while (x) {
            mx = max(mx, x%10);
            x /= 10;
        }
        return mx;
    }
    
    int maxSum(vector<int>& nums) {
        
        // idea:
        // record {digit: {}}
        
        vector<vector<int>> arr(10);
        for (int x: nums) {
            arr[maxDigit(x)].push_back(x);
        }
        
        
        int ans = -1;
        for (int i = 0; i < 10; ++i) {
            sort(arr[i].begin(), arr[i].end(), greater<>());
            if (arr[i].size() > 1)
                ans = max(ans, arr[i][0] + arr[i][1]);
        }
        return ans;
    }
};
