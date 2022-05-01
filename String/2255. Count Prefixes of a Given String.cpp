class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        
        // idea: just brute force
        int cnt = 0;
        for (auto &t: words) {
            if (s.compare(0, t.size(), t) == 0) cnt++;
        }
        return cnt;
    }
};
