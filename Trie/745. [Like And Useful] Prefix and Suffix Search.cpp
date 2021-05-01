// Trick part is suffix into prefix.

class WordFilter {

public:
    
    // trie part.
    struct trie{
        trie* next[27] = {};
        int id = -1;
    };
    
    void add(trie *root, string &s, int i){
        trie *tmp = root;
        for(char c: s){
            if(!tmp->next[c - 'a']) 
                tmp->next[c - 'a'] = new trie();
            tmp = tmp->next[c - 'a']; 
            tmp->id = i;
        }
    }
    
    int search(trie* root, string &k){
        trie *tmp = root;
        for(char c: k){
            if(!tmp) return -1;
            tmp = tmp->next[c - 'a']; 
        }
        if(!tmp) return -1;
        return tmp->id;
    }
    
    trie* root = new trie();
    
    WordFilter(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i){
            string s = words[i];
            // enum suffix
            int sz = s.size();
            for(int k = 1; k <= sz; ++k){
                string suffix = s.substr(sz - k ,k);
                string key = suffix + "{" + s;
                // add to trie structure.
                add(root, key, i);
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        string key = suffix + "{" + prefix;
        return search(root, key);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
