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

// real O(n) solution
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // goal: find if permutation of s1 is a substring of s2
        
        // idea:
        // s1 = "ab"
        // s2 = "bac"

        // we just need to record the cnt
        // if we can find the cnt == s1, find the ans
        // just using two pointer

        vector<int> cnt(26);
        int num = 0;
        for (char c: s1) {
            if (++cnt[c-'a'] == 1) num++;
        }

        int n = s2.size();
        int cur = 0;
        for (int r = 0, l = 0; r < n; ++r) {
            if (--cnt[s2[r]-'a'] == 0) cur++; // find a match letter
            while (cnt[s2[r]-'a'] < 0) { // must move
                if (cnt[s2[l]-'a']++ == 0) cur--;
                l++;
            }
            if (cur == num) return true;
        }

        return false;
    }
};
