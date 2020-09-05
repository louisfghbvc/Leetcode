// ugly solve in contest... O(N).
// 2 case all same or not all same.
// if not all same just like s1 from begin, s3 from end. and multiply. but auctually, just two count cnt a/3, and cnt 2*a/3.
// because the cut must between the string and s3 at most 1.

class Solution {
public:
    const int mod = 1e9+7;
    int numWays(string s) {
        int cnt = 0;
        for(char c: s) if(c == '1') cnt++;
        if(cnt % 3) return 0;
        long res = 0;
        if(cnt == 0 || cnt == s.size()){
            int c = 1;
            for(int i = 0; i+2 < s.size(); ++i){
                res = (res+c) %mod;
                c++;
            }
            return res;
        }
        int need = cnt/3, n = s.size();
        int lc = 0;
        cnt = 0;
        int p = 2;
        for(int i = 0; i+2 < n; ++i){
            if(s[i] == '1'){
                cnt++;
            } 
            if(cnt > need){
                p = i;
                break;
            }
            if(cnt == need){
                lc++;
            }
        }
        int c2 = 0;
        for(int j = n-1; j > p; --j){
            if(s[j] == '1') c2++;
            if(c2 == need) res++;
        }
        return ((res%mod)*(lc%mod)) % mod;
    }
};

// I think willam... wow... clean... same idea above. but formula cool 
// Author: william lin, impressive. learn a lot.
class Solution {
public:
    int M=1e9+7;
    int numWays(string s) {
        int a=0, n=s.size();
        for(char c : s)
            a+=c&1;
        if(a%3)
            return 0;
        if(!a)
            return (long long)(n-1)*(n-2)/2%M;
        long long c1=0, c2=0;
        int t=0;
        for(int i=0; i<n; ++i) {
            t+=s[i]&1;
            if(t==a/3)
                ++c1;
            if(t==2*a/3)
                ++c2;
        }
        return c1*c2%M;
    }
};
