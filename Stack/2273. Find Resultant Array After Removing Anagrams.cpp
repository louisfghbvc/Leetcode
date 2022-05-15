class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // goal: remove adjcacent anagrams
        // idea: use stack
        
        // O(LlogL)
        auto isAna = [&](string &a, string &b) {
            string ta = a;
            string tb = b;
            sort(ta.begin(), ta.end());
            sort(tb.begin(), tb.end());
            return ta == tb;
        };
        
        reverse(words.begin(), words.end());
        
        vector<string> res;
        // O(words.size() * LlogL)
        for (auto &s: words) {
            while (res.size() && isAna(res.back(), s))
                res.pop_back();
            res.push_back(s);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
