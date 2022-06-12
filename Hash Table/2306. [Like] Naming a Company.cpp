class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // goal: calculate the number valid names
        // idea: use 2D array -> first letter can convert to the other letter
        // swap -> divide twice
        // first convert s[0] to 'a'-'z'
        // then again
        
        
        unordered_set<string> st(ideas.begin(), ideas.end());
        
        int vis[26][26] = {};
        for (auto &s: ideas) {
            int ori = s[0] - 'a';
            for (int k = 0; k < 26; ++k) {
                s[0] = 'a' + k;
                if (!st.count(s)) // origin -> k
                    vis[ori][k]++;
            }
            s[0] = ori + 'a';
        }
        
        long res = 0;
        for (auto &s: ideas) {
            int ori = s[0] - 'a';
            for (int k = 0; k < 26; ++k) {
                s[0] = 'a' + k;
                if (!st.count(s)) // origin -> k
                    res += vis[k][ori];
            }
            s[0] = ori + 'a';
        }
        
        return res;
    }
};

// solution2: divide the first letter to suffix
// subtract the same suffix

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // goal: calculate the number valid names
        // idea: record the suffix of first letter    
        
        vector<unordered_set<string>> mp(26); // first letter - suffix    
            
        for (auto &s: ideas)
            mp[s[0]-'a'].insert(s.substr(1));
        
        long res = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = i+1; j < 26; ++j) {
                int same = 0;
                for (auto &s: mp[i])
                    same += mp[j].count(s);
                res += ((int)mp[i].size() - same) * ((int)mp[j].size() - same) * 2;
            }
        }
        
        return res;
    }
};
