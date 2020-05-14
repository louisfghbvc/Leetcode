// slow solve. use set. 1500ms
class Trie {
public:
    /** Initialize your data structure here. */
    set<string> st;
    Trie() {
        st.clear();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        st.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return st.count(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        for(const auto& s: st){
            if(s.substr(0, prefix.size()) == prefix) return 1;
        }
        return 0;
    }
};

// Very useful concept. Impressive. use array[26]
// three method all O(m). m is word length.
// 100ms. 43.6MB but careful memory leak. deconstructor. in the true case.

class TrieNode{
    public:
        TrieNode *next[26];
        bool is_word;
    TrieNode(bool b = 0){
        is_word = b;
        memset(next, 0, sizeof next);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *ws = root;
        for(const auto& c : word){
            if(ws->next[c - 'a'] == NULL){
                ws->next[c - 'a'] = new TrieNode();
            }
            ws = ws->next[c - 'a'];
        }
        ws->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *ws = root;
        for(const auto& c : word){
            if(ws->next[c- 'a'] == NULL){
                return 0;
            }
            ws = ws->next[c - 'a'];
        }
        return ws->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *ws = root;
        for(const auto& c : prefix){
            if(ws->next[c - 'a'] == NULL){
                return 0;
            }
            ws = ws->next[c - 'a'];
        }
        return 1;
    }
};
