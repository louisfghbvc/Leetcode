// So build the reverse trie.
// and Search the input from back to begin.
// O(QW). 

class StreamChecker {
public:
    struct node{
        bool isW;
        node *next[26];
        node(bool w = false){
            memset(next, 0, sizeof next);
            isW = w;
        }
    };
    node *root;
    string str;
    StreamChecker(vector<string>& words) {
        root = new node();
        for(auto &w: words){
            node *cur = root;
            for(int i = w.size()-1; i >= 0; --i){
                if(cur->next[w[i]-'a'] == NULL){
                    cur->next[w[i]-'a'] = new node();
                }
                cur = cur->next[w[i]-'a'];
            }
            cur->isW = true;
        }
    }
    
    bool query(char letter) {
        node* cur = root;
        str += letter;
        for(int i = str.size()-1; i >= 0 && cur; --i){
            char c = str[i];
            cur = cur->next[c-'a'];
            if(cur && cur->isW) return true;
            
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
