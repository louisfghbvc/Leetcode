// Well... this approch faster but not trie.
// Some cool solution. 140ms 30.2MB
class WordDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<string>> mp;
    WordDictionary() {
        mp.clear();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        mp[word.size()].emplace_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        for(auto &s: mp[word.size()]){
            if(helper(word, s)) return true;
        }
        return false;
    }
    bool helper(string &a, string &b){
        for(int i = 0; i < a.size(); ++i){
            if(a[i] == '.') continue;
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};

// Trie + backtracking. 
// when a word has '.' try all child dfs.
// 248ms. 42.8MB
class WordDictionary {
    struct node{
        bool isW;
        node* next[26];
        node(){
            isW = false;
            memset(next, 0, sizeof next);
        }
    };
public:
    /** Initialize your data structure here. */
    node *root;
    WordDictionary() {
        root = new node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        node* cur = root;
        for(auto &c: word){
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new node();
            }
            cur = cur->next[c-'a'];
        }
        cur->isW = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root, 0);
    }
    bool search(string &word, node* cur, int start){
        for(int i = start; i < word.size() && cur; ++i){
            char c = word[i];
            if(c != '.'){
                cur = cur->next[c-'a'];
            }
            else{
                node* tmp = cur;
                for(int k = 0; k < 26; ++k){
                    cur = tmp->next[k];
                    if(cur){
                        if(search(word, cur, i+1)) return true;
                    }
                }
            }
        }
        return cur && cur->isW;
    }
};
