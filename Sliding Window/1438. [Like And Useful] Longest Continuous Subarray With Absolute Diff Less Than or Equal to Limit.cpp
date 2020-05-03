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

// Solution2. Deque. O(N)
// if u know multiset solution. this is same idea.
// just maintain min queue, max queue.
// front == nums[i]. pop_front.
// impressive. QQ
// 120ms. 32.8MB
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, ans = 1;
        deque<int> maxd, mind;
        for(int j = 0; j < nums.size(); ++j){
            while(!maxd.empty() && maxd.back() < nums[j]) maxd.pop_back();
            while(!mind.empty() && mind.back() > nums[j]) mind.pop_back();
            maxd.push_back(nums[j]);
            mind.push_back(nums[j]);
            
            if(maxd.front() - mind.front() > limit){
                if(maxd.front() == nums[i]) maxd.pop_front();
                if(mind.front() == nums[i]) mind.pop_front();
                i++;
            }
            
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
