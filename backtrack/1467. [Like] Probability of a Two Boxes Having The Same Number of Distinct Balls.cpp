// Very hard to think backtracking.
// use left means left box remain. if 0 means can calculate combination
// O(?). 80ms.

class Solution {
public:
    const int fact[7] = {1, 1, 2, 6, 24, 120, 720};
    double total = 0, match = 0;
    double fac(int x){
        return x < 3 ? x : x*fac(x-1);
    }
    void dfs(vector<int>& balls, int p, int b1, int b2, int left, double cm1, double cm2){
        if(!left){
            for(int i = p; i < balls.size(); ++i){
                cm2 /= fact[balls[i]];
                b2 |= 1<<i;
            }
            total += cm1*cm2;
            if(__builtin_popcount(b1) == __builtin_popcount(b2))
                match += cm1*cm2;
        }
        else if(left > 0 && p < balls.size()){
            for(int c = 0; c <= balls[p]; ++c){
                dfs(balls, p+1, 
                    b1 | (c > 0 ? 1<<p : 0),
                    b2 | (c < balls[p] ? 1<<p : 0),
                    left - c,
                    cm1 / fact[c], 
                    cm2 / fact[balls[p]-c]
                   );
            }
        }
    }
    double getProbability(vector<int>& balls) {
        int n = accumulate(balls.begin(), balls.end(), 0);
        dfs(balls, 0, 0, 0, n/2, fac(n/2), fac(n/2));
        return match/total;
    }
};
