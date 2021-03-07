// Two pass. Monotonous stack
// build prev less, and next less.
// O(N).

class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> left(n, -1);
        vector<int> right(n, n);
        
        vector<int> st;
        for(int i = 0; i < n; ++i){
            while(st.size() && arr[st.back()] >= arr[i]) st.pop_back();
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
        
        st.clear();
        for(int i = n-1; i >= 0; --i){
            while(st.size() && arr[st.back()] > arr[i]) st.pop_back();
            right[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
        
        long res = 0;
        for(int i = 0; i < n; ++i){
            res = (res + arr[i] * 1LL * (i-left[i]) * 1LL * (right[i]-i)) % mod;
        }
        return res;
    }
};
