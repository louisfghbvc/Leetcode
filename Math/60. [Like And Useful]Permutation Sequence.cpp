// O(N^2). use hash concept convert permutation to a int.

class Solution {
public:
    string getPermutation(int n, int k) {
        int fac[15] = {1, 1};
        bool vis[10] = {};
        
        for(int i = 2; i < n; ++i) fac[i] = i*fac[i-1];
        k--;
        
        string res = "";
        for(int i = n-1; i >= 0; --i){
            int cnt = k/fac[i];
            for(int i = 1, j = 0; i <= n; ++i){
                if(vis[i]) continue;
                if(j++ == cnt){
                    vis[i] = 1;
                    res += (i+'0');
                    break;
                }
            }    
            k = k%fac[i];
        }
        
        return res;
    }
};
