class Solution {
public:
    
    int longestValidSubstring(string word, vector<string>& forbidden) {
        // goal: find the longest valid substring that is not forbidden
        
        // idea: two pointers
        // if current string [l:r] is invalid, all of [l:r] ... [l:n-1] is not valid
        // move left pointer
        
        // how to check all substring has forbidden
        // since the length of substring is 10
        // for each index, only check 10
        // when add a char
        // only affect last 10 index
        
        int n = word.size();
        unordered_set<string> bad;
        for (auto &w: forbidden) {
            reverse(w.begin(), w.end());
            bad.insert(w);
        }
        
        auto valid = [&](int l, int r) -> bool {
            int start = max(l, r-9);
            string tmp;
            for (int i = r; i >= start; --i) {
                tmp += word[i];
                if (bad.count(tmp)) return false;
            }
            return true;
        };
        
        // get ans
        int ans = 0;
        for (int r = 0, l = 0; r < n; ++r) {
            while (!valid(l, r)) {
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
