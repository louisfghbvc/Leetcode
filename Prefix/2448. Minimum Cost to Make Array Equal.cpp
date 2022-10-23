// ternary search O(nlogx)
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // goal: find the minimum cost such that all numbers is equal
        // idea: minimum cost -> final value always happened in nums
        // enumerete each number time: O(N^2) -> TLE
        
        // idea2: ternary search
        // func(x) -> shape is V
        // function is the cost the change all the value to x
        // ternary search 
        
        int n = nums.size();
        auto f = [&](int x) {
            long res = 0;
            for (int i = 0; i < n; ++i)
                res += (long)abs(nums[i]-x)*cost[i];
            return res;
        };
        
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while (l+1 < r) {
            int mid = (l+r)/2;
            if (f(mid) < f(mid+1)) r = mid;
            else l = mid;
        }
        
        return f(l+1);
    }
};

// Sort and enumerate all value
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // goal: find the minimum cost such that all numbers is equal
        // idea: minimum cost -> final value always happened in nums
        // enumerete each number time: O(N^2) -> TLE
        
        // idea2: ternary search
        // func(x) -> shape is V
        // function is the cost the change all the value to x
        // ternary search 
        
        // time: O(nlogx), space: O(1)
        // time: O(nlogn), space: O(N) -> optimal
        // sort the array base on value
        // prefix and suffix
        // prefix[i]: cost to index[i], cost[0:i] can merge
        
        int n = nums.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0); // [0,n-1]
        sort(order.begin(), order.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        
        // nums = [1, 2,  3, 5], cost = 
        //        [2, 14, 3, 1] <- sum => merge cost
        //         0  2  18  19*2+18     <- pre[i]: ans, all value <= nums[i] convert to nums[i]
        //        2, 16, 19, 20 <- merge cost
        
        // merge_cost = cost[0] = 2
        // i = 1
        // pre[1] = pre[0] + merge_cost * diff(2-1) = 0 + 2
        // merge_cost += cost[1] = 2+14
        
        // i = 2
        // pre[2] = pre[1] + merge_cost * diff(3-2) = 0 + 2
        // merge_cost += cost[1] = 2+14
        
        //.0.  1. 2.  3 
        // 1   2  3   5
        // 0   2
        
        // pre[i]: pre[i-1] + (nums[i] - nums[i-1]) * cost
        // 1->2->3
        //    2->3
        
        vector<long> pre(n), suf(n);
        long merge_cost = cost[order[0]];
        for (int i = 1; i < n; ++i) { 
            int diff = nums[order[i]] - nums[order[i-1]];
            pre[i] = pre[i-1] + merge_cost * diff; // cost that make all the value to nums[order[i]]
            merge_cost += cost[order[i]];
        }
        merge_cost = cost[order[n-1]];
        for (int i = n-2; i >= 0; --i) { 
            int diff = nums[order[i+1]] - nums[order[i]];
            suf[i] = suf[i+1] + merge_cost * diff;
            merge_cost += cost[order[i]];
        }
        
        long ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(pre[i] + suf[i], ans);
        }
        return ans;
    }
};

// find medium
