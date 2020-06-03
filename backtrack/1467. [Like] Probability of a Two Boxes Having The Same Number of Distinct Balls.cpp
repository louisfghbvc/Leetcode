// Very hard to think backtracking.
// cm1 is permutation. col is calculate different. cnt is left.
// and when a new ball is add, divide the ball because duplicate
// O(6^8). 28ms.

class Solution {
public:
    const int fact[7] = {1, 1, 2, 6, 24, 120, 720};
    double total = 0, match = 0;
    double fac(int x){
        return x < 3 ? x : x*fac(x-1);
    }
    void dfs(vector<int>& balls, int p, int col1, int col2, int cnt1, int cnt2, double cm1, double cm2){
        if(!cnt1 && !cnt2){
            total += cm1 * cm2;
            match += (col1==col2) * cm1 * cm2;
        }
        else if(cnt1 >= 0 && cnt2 >= 0){
            for(int b1 = 0, b2 = balls[p]; b2 >= 0; b1++, b2--){
                dfs(balls, p+1, 
                    col1 + (b1>0),
                    col2 + (b2>0),
                    cnt1 - b1,
                    cnt2 - b2,
                    cm1 / fact[b1],
                    cm2 / fact[b2]
                   );
            }
        }
        
    }
    double getProbability(vector<int>& balls) {
        int n = accumulate(balls.begin(), balls.end(), 0);
        dfs(balls, 0, 0, 0, n/2, n/2, fac(n/2), fac(n/2));
        return match/total;
    }
};
