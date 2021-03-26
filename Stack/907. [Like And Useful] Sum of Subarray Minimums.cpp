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


// Build what u can eat left, right. two pass. O(N).
class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> R(n);
        vector<int> L(n);
        
        vector<pair<int, int>> st;
        for(int i = 0; i < n; ++i){
            int cnt = 1;
            while(st.size() && arr[st.back().first] > arr[i]){
                cnt += st.back().second;
                st.pop_back();
            }
            L[i] = cnt;
            st.push_back({i, cnt});
        }
        
        st.clear();
        for(int i = n-1; i >= 0; --i){
            int cnt = 1;
            while(st.size() && arr[st.back().first] >= arr[i]){
                cnt += st.back().second;
                st.pop_back();
            }
            R[i] = cnt;
            st.push_back({i, cnt});
        }
        
        long res = 0;
        for(int i = 0; i < n; ++i){
            res += arr[i] * 1LL * L[i] * R[i]; 
            res %= mod;
        }
        
        return res;
    }
};

// O(N). One pass. prefix sum strategy.
class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        long res = 0, sum = 0;
        
        stack<pair<int, int>> st;
        for(int x: arr){
            int cnt = 1;
            while(st.size() && st.top().first >= x){
                int num = st.top().second;
                sum -= num * st.top().first;
                cnt += num;
                st.pop();
            }
            sum = ((sum + cnt * x)%mod + mod) % mod;
            res = (res+sum) % mod;
            st.push({x, cnt});
        }
        
        return res;
    }
};
