// solution 1, brute force

class Solution {
public:
    int similarPairs(vector<string>& words) {
        
        int n = words.size();
        int cnt = 0;
        
        vector<unordered_set<char>> cnv;
        for (auto &s: words)
            cnv.push_back(unordered_set<char>(s.begin(), s.end()));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                cnt += cnv[i] == cnv[j];
            }
        }
        
        return cnt;
    }
};
