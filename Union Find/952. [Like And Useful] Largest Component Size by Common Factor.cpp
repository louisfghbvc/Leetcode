// first change problem, not point to point, but to point to prime factor.
// also can build prime table to fast. but no need because sqrt(N) still small.
// I thought the idea but can not implement after union, what should I do next.
// Easily, just use a map to record the parent freqency. make it really simple.
// O(Nsqrt(N)).

class Solution {
public:
    static const int N = 100005;
    
    int p[N];
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]); 
    }
    void uni(int x, int y){
        int px = find(x), py = find(y);
        if(px == py) return;
        p[py] = px;
    }
    
    int largestComponentSize(vector<int>& A) {
        memset(p, -1, sizeof p);
        
        for(int &x: A){
            int tmp = sqrt(x);
            for(int i = 2; i <= tmp; ++i){
                if(x % i == 0){
                    uni(x, i);
                    uni(x, x/i);
                }
            }
        }
        
        unordered_map<int, int> mp;
        int res = 0;
        for(int &x: A){
            res = max(res, ++mp[find(x)]);
        }
        
        return res;
    }
};
