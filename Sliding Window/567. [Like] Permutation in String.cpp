// uhhh. similar 438. Find All Anagrams in a String.
// maintain window size. and use array.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1f(26, 0);
        for(const auto &c : s1) s1f[c-'a']++;

        vector<int> s2f(26, 0);
        for(int r = 0, l = 0; r < s2.size(); ++r){
            if(r-l+1 > s1.size()) s2f[s2[l++]-'a']--; 
            s2f[s2[r]-'a']++;
            if(r-l+1 == s1.size() && s1f == s2f) return 1;
        }
        return 0;
    }
};
