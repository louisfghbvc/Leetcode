// record maximum palindrome prefix, and suffix
// O(N)
class Solution {
public:
    vector<int> manacher(string s, bool rev = 0){
        int n = s.size();
        vector<int> d1(n); // odd
        vector<int> lmax(n, 1);
        for(int i = 0, l = 0, r = -1; i < n; ++i){
            int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
            while(i - k >= 0 && i + k < n && s[i + k] == s[i - k]){
                lmax[i + k] = max(lmax[i + k], 2*k+1);
                k++;
            }
            d1[i] = k--;
            if(i + k > r){
                l = i - k;
                r = i + k;
            }
        }
        // record maximum
        if(!rev){
            for(int i = 1; i < n; ++i)
                lmax[i] = max(lmax[i-1], lmax[i]);
        }
        else{
            reverse(lmax.begin(), lmax.end());
            for(int i = n-2; i >= 0; --i)
                lmax[i] = max(lmax[i+1], lmax[i]);
        }
        return lmax;
    }
    
    long long maxProduct(string s) {
        int n = s.size();
        auto l2r = manacher(s), r2l = manacher(string(s.rbegin(), s.rend()), 1);
        
        long long res = 0;
        for(int i = 1; i < n; ++i)
            res = max(res, l2r[i-1] * 1LL * r2l[i]);
        
        return res;
    }
};
