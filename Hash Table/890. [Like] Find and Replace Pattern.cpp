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


// Awesome Concept. Mapping to the base.
class Solution {
public:
    
    string Normalize(string s){
        map<char, char> mp;
        for(char c: s){
            if(!mp.count(c)) mp[c] = 'a' + mp.size();
        }
        string t = "";
        for(char c: s)
            t += mp[c];
        return t;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        pattern = Normalize(pattern);
        vector<string> res;
        for(string &w: words){
            string t = Normalize(w);
            if(t == pattern)
                res.push_back(w);
        }
        
        return res;
    }
};
