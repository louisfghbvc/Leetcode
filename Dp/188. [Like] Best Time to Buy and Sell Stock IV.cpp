// O(NK). space O(NK).
// main idea is like III
// tricky is when k > n/2. just like Sell II.

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(!n || !k) return 0;
        if(k >= n/2){
            int res = 0;
            for(int i = 1; i < n; ++i)
                if(prices[i] > prices[i-1]) res += prices[i] - prices[i-1];
            return res;
        }
        vector<vector<int>> state(k, vector<int>(2)); // 0: buy, 1: sell
        for(int i = 0; i < k; ++i) state[i][0] = INT_MIN;
        
        state[0][0] = -prices[0];
        for(int i = 1; i < n; ++i){
            state[0][0] = max(state[0][0], -prices[i]);
            state[0][1] = max(prices[i] + state[0][0], state[0][1]);
            
            for(int j = 1; j < k; ++j){
                state[j][0] = max(state[j-1][1] - prices[i], state[j][0]);
                state[j][1] = max(prices[i] + state[j][0], state[j][1]);
            }
            
        }
        return state[k-1][1];
    }
};

// O(NlogN) stack hard to think...
