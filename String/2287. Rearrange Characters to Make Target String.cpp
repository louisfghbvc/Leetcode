// O(N)

class Solution {
public:
    
    vector<int> encode(string &s) {
        vector<int> fre(26);
        for (char c: s)
            fre[c-'a']++;
        return fre;
    }
    
    int rearrangeCharacters(string s, string target) {
        // goal: rearrange the stirng, and compute the copies of target
        // idea, use hash table to record it
        
        auto a = encode(s);
        auto b = encode(target);
        
        int res = 1e9;
        for (int i = 0; i < 26; ++i) {
            if (b[i] == 0) continue; // no this letter
            res = min(res, a[i]/b[i]);
        }
        
        return res;
    }
};
