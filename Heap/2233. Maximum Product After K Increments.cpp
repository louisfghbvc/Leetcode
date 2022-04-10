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
