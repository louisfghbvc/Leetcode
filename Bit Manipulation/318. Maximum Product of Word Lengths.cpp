// O(N^2). Simple compress.

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> pat;
        for(auto &s: words){
            int fre = 0;
            for(char c: s) fre |= (1 << (c-'a'));
            pat.push_back(fre); 
        }
        int res = 0;
        int n = words.size();
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if((pat[i] & pat[j]) == 0){
                    res = max((int)words[i].size() * (int)words[j].size(), res);
                }
            }
        }
        return res;
    }
};

// O(Mask * Mask).
