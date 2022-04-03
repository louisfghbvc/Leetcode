class Encrypter {
    struct trieNode{
        bool isWord = false;
        trieNode* next[26] = {};
    } *root;
    
    void add(string &s) {
        trieNode* cur = root;
        for (char c: s) {
            if (!cur->next[c-'a']) cur->next[c-'a'] = new trieNode();
            cur = cur->next[c-'a'];
        }
        cur->isWord = true;
    }
    
public:
    // keys: unique
    // values: length 2
    // dict: value that is already decrypt -> hashtable record it or build it as trie
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        // build the hashtable
        for (int i = 0; i < keys.size(); ++i) {
            mapping[keys[i]] = values[i];
            rmapping[values[i]].push_back(keys[i]);
        }
        
        // add to the trie
        root = new trieNode();
        for (auto &s: dictionary)
            add(s);
    }
    
    // simple, just use hashtable to convert it
    string encrypt(string word1) {
        string res = "";
        for (char c: word1) {
            res += mapping[c];
        }
        return res;
    }
    
    // idea: use trie to search the word
    int decrypt(string word2) {
        return dfs(0, root, word2);
    }
    
    int dfs(int i, trieNode* cur, string &word) {
        if (i == word.size()) return cur && cur->isWord;
        
        int res = 0;
        string pat = word.substr(i, 2);
        for (auto &c: rmapping[pat]) {
            if (cur->next[c-'a'])
                res += dfs(i+2, cur->next[c-'a'], word);
        }
        
        return res;
    }
    
private:
    unordered_map<char, string> mapping; // keys -> values
    unordered_map<string, vector<char>> rmapping; // values -> keys
};


// Simple just use hashtable
// dictionary just encrypt that is trick
class Encrypter {
public:
    
    // iead: build all dictionary to encrypt
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); ++i)
            mapping[keys[i]] = values[i];
        for (auto &s: dictionary)
            dict[encrypt(s)]++;
    }
    
    string encrypt(string word1) {
        string res = "";
        for (char c: word1)
            res += mapping[c];
        return res;
    }
    
    int decrypt(string word2) {
        auto it = dict.find(word2);
        if (it != dict.end()) return it->second;
        return 0;
    }

private:
    unordered_map<char, string> mapping;
    unordered_map<string, int> dict;
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
