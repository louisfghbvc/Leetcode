// Collision may exist!. but rare? 
// Binary search length
// Good praticing rolling hash problem. like 1044.
// O(logR * Q).
// Another rolling hash problem 1044. 1316. 1392

class Solution {
public:
    int n;
    vector<vector<int>> tot;
    vector<long> power; // base^i
    long base, mod;
    
    long mul(long a, long b){
        __int128 a2 = a, b2 = b;
        return (a2*b2) % mod;
    }
    
    bool valid(int len){
        if(len == 0) return true;
        unordered_set<long> s; // use for record hash value
        
        for(int i = 0; i < tot.size(); ++i){
            if(tot[i].size() < len) return false;
            
            unordered_set<long> next_s;
            long hash = 0;
            for(int j = 0; j < len; ++j)
                hash = (hash + mul(power[len - j - 1], tot[i][j])) % mod;
            
            if(i == 0) s.insert(hash);
            else if(s.count(hash)) next_s.insert(hash);
            
            for(int j = len; j < tot[i].size(); ++j){
                hash = (hash - mul(power[len - 1], tot[i][j - len])) % mod;
                if(hash < 0) hash += mod;
                hash = (mul(hash, base) + tot[i][j]) % mod;
                
                if(i == 0) s.insert(hash);
                else if(s.count(hash)) next_s.insert(hash);
            }
            
            if(i) s = next_s;
            if(s.empty()) return false;
        }
        return !s.empty();
    }
    
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        this->n = n;
        this->tot = paths;
        base = n;
        mod = 1e11L + 7;
        
        int l = 0;
        int r = 1e6;
        for(int i = 0; i < paths.size(); ++i) 
            r = min(r, (int)paths[i].size());
        
        power.resize(r);
        power[0] = 1;
        for(int i = 1; i < r; ++i)
            power[i] = (power[i-1] * base) % mod;
        
        // guess the answer
        int res = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(valid(mid)){
                res = max(res, mid);
                l = mid+1;
            }
            else r = mid-1;
        }
        
        return res;
    }
};

// Suffix array...
