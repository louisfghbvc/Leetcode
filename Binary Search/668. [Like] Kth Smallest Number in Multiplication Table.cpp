// you can easily know the number of elements by divide row
// O(mlog(m*n))

class Solution {
public:
    int findKthNumber(int m, int n, int k) { 
        
        auto good = [&](int x){
            int res = 0; // compute number of bigger than x
            for(int r = 1; r <= m; ++r){
                res += min(x / r, n);
            }
            return res >= k;
        };
        
        int l = 1, r = m*n+1;
        while(l < r){
            int mid = (l+r)/2;
            if(good(mid)) r = mid;
            else l = mid+1;
        }
        
        return l;
    }
};
