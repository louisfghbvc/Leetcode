// similar to LC 247, generate all k symmetric numbers
// use memo to save memory. also no need memo can pass
// generate the depth. dfs from middle extend the mirror number.

class Solution {
public:
    
    bool ismirror(const string &s){
        int n = s.size();
        for(int i = 0; i < n/2; ++i){
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }

    long conv10(string &s, int k){
        long res = 0;
        for(char c: s)
            res = res * k + c - '0';
        return res;
    }
    
    vector<string> cache[100][10];
    vector<string>& dfs(int len, int k){
        auto& res = cache[len][k];
        if(res.size()) return res; // memo
        if(len == 0){
            res.push_back("");
            return res;
        }
        if(len == 1){
            for(int d = 0; d < k; ++d)
                res.push_back(string(1, '0' + d));
            return res;
        }        
        
        for(auto& s: dfs(len-2, k)){
            for(int d = 0; d < k; ++d){
                string pat = string(1, '0'+d) + s + string(1, '0'+d);
                if(ismirror(pat))
                    res.push_back(pat);
            }
        }
        
        return res;
    }
    
    long long kMirror(int k, int n) {
        int len = 1;
        long ans = 0;
        while(n){            
            vector<long> base10;
            for(auto &s: dfs(len, k)) if(s[0] != '0')
                base10.push_back(conv10(s, k));
            
            sort(base10.begin(), base10.end());
            for(auto &val: base10){
                if(ismirror(to_string(val))){
                    ans += val;
                    if(--n == 0) return ans;
                }
            }
            
            len++;
        }
        return ans;
    }
};

// another idea generate next base10 mirror, check is valid base k mirror
// faster
class Solution {
public:
    
    // return next palindrome number, greedy
    long nextINT(long x){
        string s = to_string(x);
        int n = s.size();
        for(int i = n/2; i >= 0; --i){
            if(s[i] != '9'){
                s[i]++;
                if(i != n-1-i) s[n-1-i]++;
                for(int j = i+1; j <= n/2; ++j) // 9..9 -> 0..0
                    s[j] = s[n-j-1] = '0';
                return stoll(s);
            }
        }
        // all 9 -> 1...1
        long res = 1;
        for(int i = 0; i < n; ++i)
            res *= 10;
        return res+1;
    }
    
    // conv to reverse k base
    string convK(long n, int k){ 
        string res = "";
        while(n){
            res += char('0' + n%k);
            n /= k;
        }
        return res;
    }
    
    bool ismirror(const string &s){
        int n = s.size();
        for(int i = 0; i < n/2; ++i){
            if(s[i] != s[n-1-i]) return false;
        }
        return true;
    }
    
    long long kMirror(int k, int n) {
        long cur = 0, res = 0;
        while(n){
            cur = nextINT(cur);
            if(ismirror(convK(cur, k)))
                res += cur, --n;
        }
        return res;
    }
};

//
