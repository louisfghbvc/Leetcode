// hashtable, subset + bitmask. O(N + M2^M)
// subset can use (subset-1) & mask to generate.

class Solution {
public:
    
    int hash(string &s){
        int res = 0;
        for(char c: s)
            res |= 1<<(c-'a');
        return res;
    }
    
    int generate(string &s, int i, int val){
        if(i >= s.size()) return mp.count(val) ? mp[val] : 0;
        int res = 0;
        res += generate(s, i+1, val|(1<<s[i]-'a'));
        res += generate(s, i+1, val);
        return res;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // convert words into map
        for(auto &s: words)
            mp[hash(s)]++;
        
        vector<int> res;
        // for each puzzles, enum puzzle subset
        // first check have first letter
        for(auto &s: puzzles){
            res.push_back(generate(s, 1, 1<<s[0]-'a') );
        }
        
        return res;
    }
private:
    unordered_map<int, int> mp;
};

// use trie
