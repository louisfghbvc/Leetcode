// BF can accepte, but key observation is that a subseqence is always be a string in strs[i].
// O(N^2 K)
class Solution {
public:
    
    bool isSubseqence(string &a, string &b){
        if(a.size() > b.size()) return false;
        int i = 0;
        for(int j = 0; j < b.size() && i < a.size(); ++j){
            if(a[i] == b[j]) i++;
        }
        return i == a.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int res = -1;
        for(int i = 0; i < n; ++i){
            int j = 0;
            for(; j < n; ++j){
                if(i == j) continue; 
                if(isSubseqence(strs[i], strs[j])) break;
            }
            if(j == n) 
                res = max(res, (int)strs[i].size());
        }
        return res;
    }
};
