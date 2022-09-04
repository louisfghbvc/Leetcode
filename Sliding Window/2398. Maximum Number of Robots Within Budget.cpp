class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        // goal: find the maximum consecutive robots, such that cost <= budget
        // max(chargeTimes) + k * sum(runningCosts) <= budget
        // idea: binary search k
        // each k, sliding window the cost value
        
        int n = runningCosts.size();
        
        
        // true, if can choose window size k. cost <= budget
        // O(n)
        auto check = [&](int k) {
            if (k == 0) return true;
            
            deque<int> dq; // monotonic decreasing queue
            long sum = 0;
            for (int i = 0; i < k; ++i) {
                while (dq.size() && chargeTimes[dq.back()] <= chargeTimes[i]) dq.pop_back(); 
                dq.push_back(i);
                sum += runningCosts[i];
            }
            
            if (chargeTimes[dq.front()] + sum*k <= budget) return true;
            for (int i = k; i < n; ++i) {
                while (dq.size() && i - dq.front() >= k) dq.pop_front();
                while (dq.size() && chargeTimes[dq.back()] <= chargeTimes[i]) dq.pop_back(); 
                dq.push_back(i);
                sum += runningCosts[i];
                sum -= runningCosts[i-k];
                if (chargeTimes[dq.front()] + sum*k <= budget) return true;
            }
            
            return false;
        };
        
        int ans = 0;
        int l = 0, r = n;
        while (l <= r) {
            int mid = (l+r)/2;
            if (check(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }
        
        return ans;
    }
};

// O(N) just sliding window
