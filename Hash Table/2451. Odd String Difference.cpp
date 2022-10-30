class Solution {
public:
    string oddString(vector<string>& words) {
        // goal: find the weird string;
        // idea: convert string to difference array
        // hashtable (diff, int)
        
        // #1 #2 #3
        // #1 #2 #4
        // #1 #2 #5
        // #5 #2 #1
        
        map<vector<int>, int> cnt; // O(nlogn * K)
        // insert O(logn * K)
            
        vector<int> pat;
        for (auto &s: words) {
            int n = s.size();
            vector<int> diff;
            for (int i = 1; i < n; ++i)
                diff.push_back(s[i]-s[i-1]);
            cnt[diff]++;
        }
        
        for (auto &[k, v]: cnt) {
            if (v == 1) pat = k;
        }
        
        for (auto &s: words) {
            int n = s.size();
            vector<int> diff;
            for (int i = 1; i < n; ++i)
                diff.push_back(s[i]-s[i-1]);
            if (diff == pat) return s;
        }
        return "";
    }
};
