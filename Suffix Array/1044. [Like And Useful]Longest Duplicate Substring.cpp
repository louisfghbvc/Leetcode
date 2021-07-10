// Rolling Hash. Now I totally understand what this algorithm do.
// thr trick is binary search the length.
// and this Rabin-Karp algorithm can find all length == k substring use sliding window concept.
// so find all substring length == k is O(N).
// and unordered_map is bucket. maybe collision, so use vector<int> save all posiible.
// total time O(NlogN)

class Solution {
public:
    int mod = 1e9+7;
    string ans;
    string valid(int len, string &s){ // rolling hash
        if(len == 0) return "";
        
        long power = 1, p = 0; // pow(power, len-1), pattern hash
        for(int i = 0; i < len-1; ++i){ 
            power = (power*26) % mod; 
        }
        
        for(int i = 0; i < len; ++i){
            p = (p*26 + (s[i]-'a')) % mod;
        }
        
        unordered_map<int, vector<int>> mp;
        mp[p] = vector<int>(1, 0);
        
        for(int i = len; i < s.size(); ++i){
            // rehash, subtract sign and add least
            p = (((p-(s[i-len]-'a')*power)*26 + s[i]-'a') % mod + mod) % mod;

            if(!mp.count(p)){
                mp[p] = vector<int>(1, i-len+1);
            }
            else{
                // now start index is i-len+1
                for(auto& start: mp[p]){
                    if(s.substr(start, len).compare(s.substr(i-len+1, len)) == 0)
                        return s.substr(start, len);
                }
                mp[p].push_back(i-len+1);
            }
        }
        
        return "";
        
    }
    string longestDupSubstring(string S) {
        ans = "";
        int l = 0, r = S.size()-1;
        while(l <= r){
            int mid = (l+r)>>1;
            string tmp = valid(mid, S);
            if(tmp.empty()){
                r = mid - 1;
            }
            else{
                if(ans.size() < tmp.size())
                    ans = tmp;
                l = mid + 1;
            }
        }
        return ans;
    }
};


// No collision, just suffix array, and build lcp. find the maximum lcp.
// O(NlogNlogN). 448ms. use vector 1488ms.
class Solution {
public:
    constexpr static int N = 3e4+5;
    int sa[N], rk[N<<1], oldrk[N<<1];
    
    bool same(int a, int b, int w){
        return oldrk[a] == oldrk[b] && oldrk[a+w] == oldrk[b+w];
    }
    
    void build_sa(string s){
        s += '$';
        int n = s.size();
        for(int i = 0; i < n; ++i) sa[i] = i, rk[i] = s[i];
        for(int w = 1; w < n; w <<= 1){
            sort(sa, sa + n, [&](int a, int b){
                return rk[a] == rk[b] ? rk[a+w] < rk[b+w] : rk[a] < rk[b];
            });
            memcpy(oldrk, rk, sizeof rk);
            rk[sa[0]] = 0;
            for(int i = 1, p = 0; i < n; ++i)
                rk[sa[i]] = same(sa[i], sa[i-1], w) ? p : ++p;
        }
    }
    
    string build_lcp(string s){
        s += '$';
        int n = s.size();
        vector<int> lcp(n);
        
        int k = 0, mx = 0, pos = 0;
        for(int i = 0; i+1 < n; ++i){
            int pi = rk[i];
            int j = sa[pi-1];
            while(s[i+k] == s[j+k]) ++k;
            lcp[pi] = k;
            if(lcp[pi] > mx){
                mx = lcp[pi];
                pos = i;
            }
            k = max(0, k-1);
        }
        
        return s.substr(pos, mx);
    }
    
    string longestDupSubstring(string s) {
        int n = s.size()+1;
        build_sa(s);
        return build_lcp(s);
    }
};
