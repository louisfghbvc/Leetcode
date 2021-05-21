// Best. O(NK).

class Solution {
public:
    
    bool match(string &a, string &pat){
        map<char, char> mp;
        // mapping to pattern
        for(int i = 0; i < a.size(); ++i){
            if(!mp.count(a[i])) mp[a[i]] = pat[i];
            if(mp[a[i]] != pat[i]) return false;
        }
        
        vector<bool> vis(26);
        // check mapping to same char
        for(auto &[k, v]: mp){
            if(vis[v-'a']) return false;
            vis[v-'a'] = 1;
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> res;
        for(string &w: words){
            if(match(w, pattern)) res.push_back(w);
        }
        
        return res;
    }
};
