// Brute BFS and priority_queue
// build table.
typedef long long LL;
class Solution {
public:
    vector<LL> uv;
    unordered_set<LL> used;
    void init(int n){
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        pq.push(1);
        while(!pq.empty()){
            LL u = pq.top(); pq.pop();
            if(used.count(u)) continue;
            used.insert(u);
            uv.push_back(u);
            if(uv.size() == n) break;
            pq.push(u*2);
            pq.push(u*3);
            pq.push(u*5);
        }
    }
    int nthUglyNumber(int n) {
        init(n);
        return uv[n-1];
    }
};

// dp. bottom up, use 3 pointer
// magic, so count where come from. pointer++
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for(int i = 1; i < n; ++i){
            dp[i] = min({dp[t2]*2, dp[t3]*3, dp[t5]*5});
            if(dp[i] == dp[t2]*2) t2++;
            if(dp[i] == dp[t3]*3) t3++;
            if(dp[i] == dp[t5]*5) t5++;
        }
        return dp.back();
    }
};
