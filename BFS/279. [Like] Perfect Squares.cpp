// BFS + prune 832ms.
class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        queue<int> q;
        unordered_set<int> st;
        for(int i = 1; i*i <= n; ++i){
            v.push_back(i*i);
            q.push(i*i);
            st.insert(i*i);
        } 
        int dep = 1;
        while(!q.empty()){
            // cout << q.size() << endl;
            for(int s = q.size()-1; s >= 0; --s){
                int cur = q.front(); q.pop();  
                // cout << dep << " " << cur << endl;
                if(cur == n) return dep;
                for(int i = 0; i < v.size(); ++i){
                    if(cur + v[i] > n) break;
                    if(st.count(cur+v[i])) continue;
                    st.insert(cur+v[i]);
                    q.push(cur+v[i]);
                }
            }
            dep++;
        }
        return n;
    }
};

// Dp super fast 12ms
// from small. bottom-up, like coin change.
// so 1, 2, 3 = 1, 2, 3 and 4 can be just 1. dp[0] = 0;
// O(Nsqrt(N)). Memorize. not duplicate
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp = {0};
        while(dp.size() <= n){
            int m = dp.size(), cur = INT_MAX;
            for(int i = 1; i*i <= m; ++i)
                cur = min(cur, dp[m-i*i]+1);
            dp.push_back(cur);
        }
        return dp[n];
    }
};
