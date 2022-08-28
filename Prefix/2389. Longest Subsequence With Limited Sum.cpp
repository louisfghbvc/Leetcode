class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // goal: for each query, calculate the maximum size that you can take
        // idea: sort nums
        // for each query try to calculate the how many nums can take
        // O(QN)
        
        sort(nums.begin(), nums.end());
        
        
        int n = nums.size();
        // until sum > x
        // use prefix sum
        // binary search the prefix sum, choose largest i, that pre[i] <= x
        auto cal = [&](int x) {
            int j = 0, sum = 0;
            while (j < n && sum + nums[j] <= x) {
                sum += nums[j];
                j++;
            }  
            return j;
        };
        
        vector<int> ans;
        for (auto &q: queries)
            ans.push_back(cal(q));
        return ans;
    }
};

// solution2: use binary search to speed up
