class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // goal: return the answer0 is distinct and not in nums2
        
        set<int> ans1(nums1.begin(), nums1.end()), ans2(nums2.begin(), nums2.end());
        
        vector<vector<int>> res(2);
        for (auto &x: ans1)
            if (!ans2.count(x))
                res[0].push_back(x);
        
        for (auto &x: ans2)
            if (!ans1.count(x))
                res[1].push_back(x);
        
        return res;
    }
};

// set difference !! trick
