// Record max and min possible, and use prefix sum to know that candies that you can eat.
// O(N). use two lines intersect.
class Solution {
public:

    vector<bool> canEat(vector<int>& cnt, vector<vector<int>>& qy) {
        int n = cnt.size();
        vector<long> pre(n+1);
        for(int i = 1; i <= n; ++i) pre[i] += pre[i-1] + cnt[i-1];
        
        vector<bool> res;
        for(auto &q: qy){
            int ft = q[0], fd = q[1], d = q[2];
            long okl = pre[ft]+1, okr = pre[ft+1];
            long l = fd+1, r = (long)(fd+1)*d;
            
            if(r < okl || l > okr) res.push_back(0);
            else res.push_back(1);
            
        }
        
        return res;
    }
};
