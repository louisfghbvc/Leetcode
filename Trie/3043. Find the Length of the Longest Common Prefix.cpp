class Solution {
public:

    struct TrieNode {
        TrieNode* next[10]{};
    } *root;

    void add(int x) {
        string s = to_string(x);
        TrieNode* cur = root;
        for (char c: s) {
            if (!cur->next[c-'0']) cur->next[c-'0'] = new TrieNode;
            cur = cur->next[c-'0'];
        }
    }

    int search(int x) {
        string s = to_string(x);
        TrieNode* cur = root;
        int ans = 0;
        for (char c: s) {
            if (!cur->next[c-'0']) break;
            cur = cur->next[c-'0'];
            ans++;
        }
        return ans;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // goal: find the longest common prefix of a word
        // idea:
        // just convert int to trie tree
        // and each time we can search the word in trie to find the longest prefix

        root = new TrieNode;
        for (int x: arr1)
            add(x);
        
        int ans = 0;
        for (int x: arr2)
            ans = max(ans, search(x));
        return ans;
    }
};
