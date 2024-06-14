class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        // goal: choose any element by add 1, maximum the product
        // k <= 10^5
        // simulate each operation
        // min-heap
        const int mod = 1e9+7;
        priority_queue<int, vector<int>, greater<>> pq(nums.begin(), nums.end());
        while (k--) {
            int x = pq.top(); pq.pop();
            pq.push(x+1);
        }
        
        long res = 1;
        while (pq.size()) {
            res *= pq.top(); pq.pop();
            res %= mod;
        }
        return res;
    }
};

// Approach2: guess the min value then compute the answer

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        // idea: binary search the min value, guess the minvalue
        // F(mn) is valid
        // then all F(mn-1), F(mn-2), ... is all valid
        // using the min value to get the ans

        auto cal = [&](int mn) -> long {
            long cnt = 0;
            for (int x: nums) {
                cnt += max(mn-x, 0);
            }
            return cnt;
        };
 
        int l = *min_element(nums.begin(), nums.end()), r = (*max_element(nums.begin(), nums.end())) + k;
        int ans = l;
        while (l <= r) {
            int m = (l+r)/2;
            if (cal(m) <= k) ans = m, l = m+1;
            else r = m-1;
        }

        int mod = 1e9+7;
        long res = 1;
        k -= cal(ans);
        for (int x: nums) {
            if (x <= ans) {
                if (k > 0) {
                    x = ans+1;
                    k--;
                }
                else {
                    x = ans;
                }
            }
            res = res * x % mod;
        }

        return res;
    }
};
