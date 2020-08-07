// O(N).
// when merge. sort from small. because no duplicate(only 26 possible). so just sort first.
// not ISMP. because need all choosen. so not sort R.

class Solution {
public:
    typedef pair<int, int> ii;
    vector<int> partitionLabels(string S) {
        int n = S.size();
        vector<int> l(26, n+1);
        vector<int> r(26, -1);
        
        for(int j = 0; j < n; ++j){
            l[S[j]-'a'] = min(l[S[j]-'a'], j);
            r[S[j]-'a'] = max(r[S[j]-'a'], j);
        }
        
        vector<ii> tmp;
        for(int i = 0; i < 26; i++){
            int L = l[i], R = r[i];
            if(R == -1) continue;
            for(int k = l[i]; k <= R; ++k){
                L = min(L, l[S[k]-'a']);
                R = max(R, r[S[k]-'a']);
            }
            if(L == l[i]){
                tmp.push_back({L, R});
            }
        }
        
        sort(tmp.begin(), tmp.end());
        vector<int> res;
        int i = -1;
        for(auto &[L, R]: tmp){
            if(L > i){
                res.push_back(R-L+1);
                i = R;
            }  
        }
        return res;
    }
};

// Solution2. Optimal. Two Pointer
// O(N). Autually only record the last index.
// next from begin to end. try to find right most.
// when cur == right most. that is a ans. then move pointer.
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int n = S.size();
        int last[26] = {};
        
        for(int i = 0; i < n; ++i){
            last[S[i]-'a'] = i;
        }
        
        int r = 0, l = 0;
        for(int i = 0; i < n; ++i){
            r = max(last[S[i]-'a'], r);
            if(i == r){
                res.push_back(r-l+1);
                l = i+1;
            }
        }
        
        return res;
    }
};
