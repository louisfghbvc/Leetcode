class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // goal: count the complete subarray
        // subarray-> distinct element is equal to all nums distinct
        
        // 1 <= nums.size() <= 2000
        // 1 <= nums[i] <= 2000
        
        // 1 2 3 3 1 2 3, ans = 5+3+2+2+1 = 13
        // [   ]
        //   [     ]
        //     [     ]
        //       [   ]
        //         [   ]
        
        // idea: two pointers
        // count the number of distinct element first
        // l, r
        // move r pointer, when distinct count is match == all element -> calculate the ans
        // move l pointer until distinct < all
        
        int ans = 0;
        unordered_set<int> all(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<int> cnt(2005);
        int distinct = 0;
        for (int r = 0, l = 0; r < n; ++r) {
            distinct += ++cnt[nums[r]] == 1;
            while (distinct == all.size()) {
                ans += n-r;
                distinct -= --cnt[nums[l++]] == 0;
            }
        }
        
        return ans;
    }
};
