class Solution {
public:    
    int minOperations(vector<int>& nums, int k) {
        // goal: find the min ops to make at least k peak
        // idea:
        // dp => maybe too slow
        // 2 (1 2 2) 1
        // 1 (2 3 1) 2 3

        // each position peak or not
        // when i peak, i+1 must not peak

        // impossible? k > n/2
        int n = nums.size();
        if (k > n/2) return -1;

        // regret greedy
        // compute cost first
        // we could use min heap to choose k peaks
        // e.g, k = 2
        // 10 1 9 20 30
        // 1) 1 
        // 2) 10 + 9 - 1
        
        vector<long> C(n);
        for (int i = 0; i < n; ++i) {
            C[i] = max(0, max(nums[(i-1+n)%n], nums[(i+1)%n])+1-nums[i]);
        }

        using T = pair<long, int>;
        priority_queue<T,vector<T>,greater<>> pq;

        // init
        vector<int> vis(n), left(n), right(n);
        for (int i = 0; i < n; ++i) {
            pq.push({C[i], i});
            left[i] = (i-1+n)%n;
            right[i] = (i+1)%n;
        }

        long ans = 0;
        for (int i = 0; i < k; ++i) {
            while (pq.size() && vis[pq.top().second])
                pq.pop();

            auto [c, u] = pq.top(); pq.pop();
            ans += c;

            int l = left[u];
            int r = right[u];
            vis[l] = vis[r] = true;

            // merge left, right
            C[u] = C[l] + C[r] - c;
            pq.push({C[u], u});

            // update left, right link
            int ll = left[l], rr = right[r];
            left[u] = ll;
            right[u] = rr;
            right[ll] = u;
            left[rr] = u;
        }

        return ans;
    }
};
