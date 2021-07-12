// Awesome mapping two to other form
// O(N).
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp1(256, -1), mp2(256, -1);
        for(int i = 0; i < s.size(); ++i){
            if(mp1[s[i]] != mp2[t[i]]) return false;
            mp1[s[i]] = mp2[t[i]] = i;
        }
        return true;
    }
};

// O(N). 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> mp(256, -1);
        vector<bool> vis(256);
        for(int i = 0; i < s.size(); ++i){
            if(mp[s[i]] == -1){
                mp[s[i]] = t[i];
                if(vis[t[i]]) return false;
                vis[t[i]] = 1;
            }
            else{
                if(t[i] != mp[s[i]]) return false;
            }
        }
        return true;
    }
};
