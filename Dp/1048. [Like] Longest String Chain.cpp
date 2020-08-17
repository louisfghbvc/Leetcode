// O(N^2*256). + Prune. 1296ms. almost TLE
// first sort by len.
// and try all j<i. check if ignore 1 char can same or not.
// slow.
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> pre(n);
        
        sort(words.begin(), words.end(), [&](string &a, string &b){
            return a.size() < b.size();
        });
        
        for(int i = 0; i < n; ++i){
            pre[i] = 1;
            int ilen = words[i].size();
            for(int j = 0; j < i; ++j){
                if(words[j].size()+1 != ilen) continue;
                for(int b = 0; b < ilen; ++b){
                    string s = "";
                    for(int k = 0; k < ilen; ++k){
                        if(k != b) s += words[i][k];
                    }
                    if(s == words[j]){
                        pre[i] = max(pre[i], pre[j]+1);
                        break;
                    }
                } 
            }
        }
        
        return *max_element(pre.begin(), pre.end());
    }
};

// 100ms O(N^2*16). Space: O(N).
// Optimal.
class Solution {
public:
    bool isPred(string &a, string &b){
        bool diff = 0;
        for(int i = 0, j = 0; i < a.size() && j < b.size(); ++i, ++j){
            if(a[i] != b[j]){
                if(diff) return 0;
                diff = 1;
                --i;
            }
        }
        return 1;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> pre(n);
        
        sort(words.begin(), words.end(), [&](string &a, string &b){
            return a.size() < b.size();
        });
        
        for(int i = 0; i < n; ++i){
            pre[i] = 1;
            for(int j = 0; j < i; ++j){
                if(words[j].size()+1 != words[i].size()) continue;
                if(isPred(words[j], words[i])){
                    pre[i] = max(pre[i], pre[j]+1);
                }
            }
        }
        
        return *max_element(pre.begin(), pre.end());
    }
};

// O(NlogN+N*256). Best.
// 296ms. but time complexity is better.
// use map dp. so try all length. and record in map.
// very cool.

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> dp;
        
        sort(words.begin(), words.end(), [&](string &a, string &b){
            return a.size() < b.size();
        });
        
        int res = 0;
        for(string &s: words){
            for(int k = 0; k < s.size(); ++k){
                dp[s] = max(dp[s], dp[s.substr(0, k) + s.substr(k+1)]+1);    
            }
            res = max(res, dp[s]);
        }
        
        return res;
    }
};
