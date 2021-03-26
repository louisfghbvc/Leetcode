// O(NS). Simple count sort maintain maximum.

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> res;
        int fre[26] = {};
        for(auto &s: B){
            int bfre[26] = {};
            for(char &c: s)
                bfre[c-'a']++;
            for(int i = 0; i < 26; ++i){
                fre[i] = max(fre[i], bfre[i]);
            }
        }
        
        for(auto &s: A){
            int afre[26] = {};
            for(char c: s)
                afre[c-'a']++;
            bool ok = true;
            for(int i = 0; i < 26; ++i){
                if(afre[i] < fre[i]) ok = false;
            }
            if(ok) res.push_back(s);
        }
        
        return res;
    }
};
