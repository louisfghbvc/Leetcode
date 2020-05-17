// Simple sliding window. no max, min or what. just window size fre maintain.
// use lambda or vector can be compare. cool.

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> sf(26, 0);
//         vector<int> tar(26, 0);
//         for(const auto &c: p) tar[c-'a']++;
//         vector<int> ans;
//         int l = 0, len = (int)p.size();   
//         for(int r = 0; r < s.size(); ++r){
//             if(r-l+1 > len) sf[s[l++]-'a']--;
//             sf[s[r]-'a']++;
//             if(r-l+1 == len && sf == tar) ans.push_back(l);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        auto com = [](vector<int> &a, vector<int> &b){
            for(int i = 0; i < 26; ++i){
                if(a[i] != b[i]) return 0;
            }
            return 1;
        };
        vector<int> sf(26, 0);
        vector<int> tar(26, 0);
        for(const auto &c: p) tar[c-'a']++;
        vector<int> ans;
        int l = 0, len = (int)p.size();   
        for(int r = 0; r < s.size(); ++r){
            if(r-l+1 > len) sf[s[l++]-'a']--;
            sf[s[r]-'a']++;
            if(r-l+1 == len && com(sf, tar)) ans.push_back(l);
        }
        return ans;
    }
};
