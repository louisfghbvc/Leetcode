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
