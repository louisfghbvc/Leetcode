// each i find factor. sqrt(i). 
// O(Nsqrt(N))
// and just connected the edge > threshold.

class Solution {
public:
    int p[10005];
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        p[b] = a;
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        memset(p, -1, sizeof p);
        for(int i = 1; i <= n; ++i){
            for(int k = 1; k*k <= n; ++k){
                if(i%k == 0){
                    if(k > threshold) uni(i, k);
                    if(i/k > threshold) uni(i, i/k);
                }
            }
        }
        vector<bool> res;
        for(auto& q: queries){
            int a = find(q[0]), b = find(q[1]);
            res.push_back(a == b);
        }
        
        return res;
    }
};
