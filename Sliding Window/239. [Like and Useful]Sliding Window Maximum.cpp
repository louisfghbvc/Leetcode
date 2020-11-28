//64ms 13MB
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
	vector<int> dq;
        for(int i = 0; i < nums.size(); ++i){
            if(!dq.empty() && dq.front() == i - k) dq.erase(dq.begin());
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};


// easy to understand. maintain a max queue. say 1 is max. 2 is small max. ...
// and if queue size > k. check now is that index. and erase.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int r = 0, l = 0; r < nums.size(); ++r){
            while(dq.size() && nums[dq.back()] < nums[r]) dq.pop_back();
            dq.push_back(r);
            if(dq.size() && r-l+1 > k && dq.front() == l++) dq.pop_front();
            if(r-l+1 == k) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

// lazy. multiset. O(NlogN).
