class Solution {
public:

    int mod = 1e9+7;
    long fpow(long a, long b) {
        long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a*a % mod;
            b >>= 1;
        }
        return res;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // goal: find the final value
        // when k is very big
        
        // idea:
        // each time need choose minimum one
        // m = 1 -> no change
        
        // m > 1
        // 1 4 16 => do k times
        
        // formulate
        // arr[i1]*(m^k1), arr[i2]*(m^k2), k1 + k2 = k
        
        // consider sort
        // arr[i]*m^k1 > arr[i+1]
        // when all value is greater than max
        
        // 1 3 5
        // a b c 
        //       b*m^1 a*m^3 c*m^1
        //         6    8     10
        //         12   16    20
        //         24   32    40
        // m = 2
        // 1  3   5
        //      4
        // 
        // m = 3
        // 4  7 10
        //         12 21  
        //               30

        // after looking the solution:
        // arr[i] <= max
        // arr[i] * m > max      
        // arr[i] * m <= max * m 

        // after arr[i] * m > max
        // we have cycle happen
        // consider
        // a1 < a2 < a3 
        // a1 * m > a3
        // a3 < a1 * m < a2 * m

        if (multiplier == 1) return nums;
        
        using T = pair<long, long>;
        int n = nums.size();
        priority_queue<T, vector<T>, greater<>> minHeap;
        for (int i = 0; i < n; ++i)
            minHeap.emplace(nums[i], i);
        int mx = ranges::max(nums);
        
        while (k && minHeap.top().first <= mx) {
            k--;
            auto [val, i] = minHeap.top(); minHeap.pop();
            val *= multiplier;
            minHeap.emplace(val, i);
        }

        // now we can do cycle!
        vector<T> tmp;
        while (minHeap.size()) {
            tmp.push_back(minHeap.top()); minHeap.pop();
        }

        int time = k / n;
        for (int i = 0; i < n; ++i) {
            int add = i < k % n;
            tmp[i].first = tmp[i].first % mod * fpow(multiplier, time+add) % mod;
        }

        vector<int> ans(n);
        for (auto &[v, i]: tmp)
            ans[i] = v;
        
        return ans;
    }
};
