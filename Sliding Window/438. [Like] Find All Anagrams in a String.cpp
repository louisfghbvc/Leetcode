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


// use O(1) compare
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // build p frequencies
        // two pointers approach 
        
        vector<int> fre(26);
        int size = 0;
        for(char c: p){
            if(++fre[c-'a'] == 1) size++;
        }
        
        vector<int> res;
        for(int r = 0, l = 0; r < s.size(); ++r){
            if(--fre[s[r]-'a'] == 0) size--;
            while(size == 0){
                if(r - l + 1 == p.size()) // npte !!!! 
                    res.push_back(l);
                if(++fre[s[l]-'a'] == 1) ++size;
                l++;
            }  
        }
        
        return res;
    }
};
