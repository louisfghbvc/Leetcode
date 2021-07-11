// O(N^2). Enum  two.
class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i+1; j <= n; ++j){
                int sq = i*i + j*j;
                int r = sqrt(sq);
                if(r*r == sq && r <= n) res += 2;
            }
        }
        return res;
    }
};


// BF O(N^3)
