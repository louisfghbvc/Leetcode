// O(N^2) Brute-Force
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;
        for(int i = 0; i < n; ++i){
            int j;
            for(j = i+1; j < n; ++j){
                if(prices[i] >= prices[j]) break;
            }
            if(j != n)
                ans[i] = prices[i]-prices[j];
        }
        return ans;
    }
};

// O(N). Monotone Stack
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!st.empty() && prices[st.top()] >= prices[i]){
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};
