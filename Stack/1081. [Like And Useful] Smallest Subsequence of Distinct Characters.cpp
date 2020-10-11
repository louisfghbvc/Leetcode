// Same as 316
// more clean. stack and Greedy concept.
// O(N).

class Solution {
public:
    string smallestSubsequence(string s) {
        int fre[26] = {};
        int use[26] = {};
        for(char c: s) fre[c-'a']++;
        string res = "";
        for(char c: s){
            fre[c-'a']--;
            if(use[c-'a']++ > 0) continue;
            while(res.size() && res.back() > c && fre[res.back()-'a']){
                use[res.back()-'a'] = 0;
                res.pop_back();
            }
            res += c;
        }
        return res;
    }
};
