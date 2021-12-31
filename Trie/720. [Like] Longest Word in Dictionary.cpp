// O(Number of characters)

class Solution {
    
    struct trieNode{
        trieNode* next[26] = {NULL};
        bool isWord = false;
    } *root;
    
    void add(string &s){
        trieNode *cur = root;
        for(char c: s){
            if(!cur->next[c-'a']) cur->next[c-'a'] = new trieNode();
            cur = cur->next[c-'a'];
        }
        cur->isWord = true;
    }
    
    string res;
    void dfs(trieNode* cur, string &ans){
        if(ans.size() > res.size()){
            res = ans;
        }
        for(int i = 0; i < 26; ++i){
            if(cur->next[i] && cur->next[i]->isWord){
                ans.push_back('a'+i);
                dfs(cur->next[i], ans);
                ans.pop_back();
            }
        }
    }
    
public:
    string longestWord(vector<string>& words) {
        root = new trieNode();
        
        for(auto &s: words)
            add(s);
        
        res = "";
        string ans = "";
        dfs(root, ans);
        
        return res;
    }
};


// O(N^2).
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [&](auto &a, auto &b){
            return a.size() < b.size();    
        });
        
        unordered_set<string> valid;
        string ans = "";
        for(auto &s: words){
            if(s.size() == 1 || valid.count(s.substr(0, s.size()-1))){
                valid.insert(s);
                if(ans.size() < s.size()) ans = s;
                else if(ans.size() == s.size() && ans > s) ans = s;
            }
        }
        
        return ans;
    }
};
