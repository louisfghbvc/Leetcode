// slow solve. use set.
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

