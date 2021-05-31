// space is big. need better. but simple. 

class Solution {
public:
    struct trie{
        trie* next[26] = {};
        vector<string> candidate = {};
    };
    
    void add(trie* root, string &s){
        trie* cur = root;
        for(char c: s){
            if(!cur->next[c-'a']) cur->next[c-'a'] = new trie();
            cur = cur->next[c-'a'];
            if(cur->candidate.size() < 3)
                cur->candidate.push_back(s);
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        trie* root = new trie();
        
        sort(products.begin(), products.end());
        
        for(auto &s: products)
            add(root, s);
        
        vector<vector<string>> res;
        bool f = 1;
        for(char c: searchWord){
            if(root->next[c-'a'] && f){
                root = root->next[c-'a'];
                res.push_back(root->candidate);
            }
            else{
                f = 0;
                res.push_back({});
            }
        }
        
        return res;
    }
};

// Binary Search, Tricky.
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        auto it = products.begin();
        sort(it, products.end());
        
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, products.end(), cur);
            for (int i = 0; i < 3 && it + i != products.end(); i++) {
                string& s = *(it + i);
                if (s.find(cur) == -1) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        
        return res;
    }
};
