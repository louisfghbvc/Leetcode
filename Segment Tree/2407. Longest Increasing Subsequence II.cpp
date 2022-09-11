class Solution {
public:
    
    vector<int> seg; // maximum interval tree
    
    void update(int idx, int l, int r, int pos, int x) { 
        if (l == r && pos == l) { // update the leaf node, range = r-l+1=1
            seg[idx] = x;
            return;
        }
        int mid = (l+r)/2; // [0, 5] -> pos=1, mid=2, [0, 2], [3, 5]
        if (pos <= mid)
            update(idx*2, l, mid, pos, x);
        else
            update(idx*2+1, mid+1, r, pos, x);
        seg[idx] = max(seg[idx*2], seg[idx*2+1]); // get information from child
    };
    
    int query(int idx, int l, int r, int ll, int rr) {
        if (r < ll || l > rr) return 0; // impossible, 
        if (ll <= l && r <= rr) return seg[idx]; // [l, r] in [ll, rr]
        int mid = (l+r)/2; 
        int left = query(idx*2, l, mid, ll, rr);
        int right = query(idx*2+1, mid+1, r, ll, rr);
        return max(left, right);
    };
    
    int lengthOfLIS(vector<int>& nums, int k) {
        // goal: find the longest subsequence such that adjacent value difference is at most k
        // idea: dp
        // dp[i]: maximum length of lis
        // O(N^2) -> too slow
        // follow up: O(max -> 1e9) -> sparse segment tree or convert nums to [0-n-1]
        
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        
        seg.resize(4*mx);
        
        // dp[i] = max of first diff k number + 1 
        // can be used [nums[i] - k, nums[i] - 1] -> find maximum of this segment
        // idea2: use segment to query max, update the maximum
        //    [0, mx]
        //.  /.     \
        // [0, mid]  [mid+1, mx]  -> max dp of this interval
        
        int ans = 0;
        for (int x: nums) {
            // find [x-k, x-1]
            int mx_interval = query(1, 0, mx, max(x-k, 0), x-1);
            ans = max(mx_interval + 1, ans);
            update(1, 0, mx, x, mx_interval+1);
        }
        
        return ans;
    }
};
