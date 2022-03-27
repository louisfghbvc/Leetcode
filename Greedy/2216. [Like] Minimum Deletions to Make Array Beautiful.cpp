// simulate space: O(N)

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        // goal: n is even and nums[i] != nums[i+1] for all i%2 = 0
        // idea: simulate the process, if last is same and check the ans.size is odd, should popout 
        // edgecase is when ans.size() is odd should popout 1
       
        vector<int> ans;
        for (int x: nums) {
            while (ans.size() && ans.size() % 2 && ans.back() == x) ans.pop_back();
            ans.push_back(x);            
        }
        
        // odd
        if (ans.size() % 2) ans.pop_back();
        
        return nums.size() - ans.size();
    }
};

// optimal O(1)
