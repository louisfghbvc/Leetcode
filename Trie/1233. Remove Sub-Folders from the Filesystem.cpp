class Solution {
public:

    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        bool isFolder = false;
    } *root;

    void add(string& s) {
        auto* cur = root;
        for (char c: s) {
            if (!cur->next[c]) cur->next[c] = new TrieNode;
            cur = cur->next[c];
        }
        cur->isFolder = true;
    }

    bool search(string& s) {
        auto* cur = root;
        for (char c: s) {
            if (c == '/') {
                if (cur->isFolder) return true;
            }
            cur = cur->next[c];
        }
        return false;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        // goal: remove the subfolders
        // idea:
        // a -> b -> c
        // we should remove a,b,c    

        // /a
        // /a/b

        // use trie
        // build the trie
        // if we have a prefix that is a word

        // forgot...
        // must be /

        // try brute force
        // we record the prefix
        // if we find a prefix is existed. need erase

        root = new TrieNode;
        for (auto &s: folder)
            add(s);

        vector<string> res;
        for (auto& s: folder)
            if (!search(s))
                res.push_back(s);
        return res;
    }
};
