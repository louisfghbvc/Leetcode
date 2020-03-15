//must mod after ans, try to maintain a max interval speed. sort decreasing efficiency. O(NlogN) 
typedef long long LL;
class Solution {
public:
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v; 
        for(int i = 0; i < n; ++i){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        LL tot_speed = 0, res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; ++i){
            tot_speed += v[i].second;
            pq.push(v[i].second);
            if(pq.size() > k){
                tot_speed -= pq.top(); pq.pop();
            }
            res = max(res, tot_speed * v[i].first);
        }
        
        return res % mod;
    }
};
