// Solution1. Multiset. O(NlogN)
// Use one params. to record now_index. maintain bag (max-min) <= limit
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1;
        multiset<int> bag;
        for(int i = 0, j = 0; i < nums.size(); ++i){
            bag.insert(nums[i]);
            while(*bag.rbegin() - *bag.begin() > limit){
                bag.erase(bag.find(nums[j++]));
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};

// Solution2. Deque
