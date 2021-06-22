// Record words key and end position.
// and just go through s. make all next step.
// O(S + W * L)
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<pair<int, int>> arr[26];
        
        for(int i = 0; i < words.size(); ++i){
            arr[words[i][0] - 'a'].push_back({i, 0});
        }
        
        int res = 0;
        for(char c: s){
            int i = c - 'a';
            auto can = arr[i];
            arr[i].clear();
            
            for(auto &[key, len]: can){
                if(len+1 == words[key].size()) res++;
                else arr[words[key][len+1] - 'a'].push_back({key, len+1});
            }
        }
        
        return res;
    }
};

// Binary search. record index.
// O(WLlogS).

class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> ind(26);
        for(int i = 0; i < s.size(); ++i)
            ind[s[i] - 'a'].push_back(i);
        
        auto check = [&](string &w){ // O(WlogS)
            int i = 0;
            for(int j = 0; j < w.size(); ++j){
                int k = w[j] - 'a';
                auto p = lower_bound(ind[k].begin(), ind[k].end(), i);
                if(p == ind[k].end()) return false;
                i = 1 + *p;
            }
            return true;
        };
        
        int res = 0;
        for(auto &w: words){
            if(check(w)) res++;
        }
        
        return res;
    }
};
