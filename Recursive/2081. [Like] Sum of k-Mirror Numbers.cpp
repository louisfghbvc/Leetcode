// similar to LC 247, generate all k symmetric numbers
// use memo to save memory.
// generate the depth.

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

// No memo
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
    
    vector<string> dfs(int len, int k){
        vector<string> res;
        if(len == 0) return {""};
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
