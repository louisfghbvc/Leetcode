// solution1. 1D dp subarray. circle can split into total - middle min subarray.
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, curMax = 0, curMin = 0, mx = INT_MIN, mn = INT_MAX;
        for(const int &a: A){
            curMax = max(a, a+curMax);
            curMin = min(a, a+curMin);
            mx = max(mx, curMax);
            mn = min(mn, curMin);
            total += a;
        }
        return mx > 0 ? max(mx, total-mn): mx;
    }
};
// solution2 sliding window. hard to think.
// Maintain max.
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        vector<int> pre(2*n+1, 0);
        for(int i = 0; i < 2*n; ++i){
            pre[i+1] = pre[i] + A[i%n];
        }
        int ans = A[0];
        deque<int> dq;
        dq.push_back(0);
        for(int j = 1; j <= 2*n; ++j){
            if(dq.front() < j-n) dq.pop_front();
            ans = max(ans, pre[j] - pre[dq.front()]);
            while(!dq.empty() && pre[dq.back()] >= pre[j])
                dq.pop_back();
            dq.push_back(j);
        }
        return ans;
    }
};
