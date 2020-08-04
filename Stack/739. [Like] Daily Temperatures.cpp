// Use next array. backward.
// O(NW).
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res = vector<int>(n, 0);
        int id[105];
        memset(id, -1, sizeof id);
        id[T[n-1]] = n-1;
        for(int i = n-2; i >= 0; --i){
            id[T[i]] = i;
            for(int k = T[i]+1; k <= 100; ++k){
                if(id[k] == -1) continue;
                if(res[i] == 0) res[i] = id[k]-i;
                else res[i] = min(res[i], id[k]-i);
            }
        }
        return res;
    }
};

// O(N). use stack, monotonous. trick
// just begin to end. when T[now] > T[stack.top()].
// then calculate res[stack.top()] = now - top.
// just like if countered a bigger value then calculate stack value. because that make smallest.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res = vector<int>(n, 0);
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(st.size() && T[st.top()] < T[i]){
                int k = st.top(); st.pop();
                res[k] = i-k;
            }
            st.push(i);
        }
        return res;
    }
};
