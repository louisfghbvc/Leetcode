// Just use bit manipulation and backtracking.
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> fre(26);
        for(char c: letters)
            fre[c - 'a']++;
        
        int n = words.size();
        int res = 0;
        for(int S = 1; S < 1<<n; ++S){
            vector<int> tmp = fre;
            bool ok = 1;
            int val = 0;
            for(int i = 0; i < n; ++i){
                if(S >> i & 1){
                    for(char c: words[i]){
                        if(--tmp[c - 'a'] < 0) ok = false;
                        val += score[c - 'a'];
                    }
                }
            }
            if(ok) res = max(res, val);
        }
        
        return res;
    }
};
