class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        // goal: find the queries, such that each word should be in dictionary
        // idea: modified dictionary
        // a word, change to '*'
        // and two edit, change to '*', '*'
        
        // idea2: linear compare the dictionary
        // O(N*M*L)
        
        vector<string> res;
        for (auto &s: queries) {
            int n = s.size();
            for (auto &w: dictionary) {
                int cnt = 0;
                for (int j = 0; j < n; ++j) {
                    if (w[j] != s[j]) cnt++;
                }
                if (cnt <= 2) {
                    res.push_back(s);
                    break;
                }
            }
        }
        return res;
    }
};
