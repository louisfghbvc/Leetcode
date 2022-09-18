class Solution {
public:
    
    struct trieNode {
        trieNode* next[26] = {};
        int cnt = 0;
    };
    
    void add(trieNode* root, string &s) {
        for (char c: s) {
            if (!root->next[c-'a']) root->next[c-'a'] = new trieNode();
            root = root->next[c-'a'];
            root->cnt++;
        }
    }
    
    int search(trieNode* root, string &s) {
        int ans = 0;
        for (char c: s) {
            root = root->next[c-'a'];
            if (root)
                ans += root->cnt;
            else
                break;
        }
        return ans;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        // goal: find the sum of prefix in the words
        // idea: use trie
        
        // O(NL)
        
        trieNode* root = new trieNode();
        for (auto &s: words)
            add(root, s);
        
        vector<int> ans;
        for (auto &s: words) 
            ans.push_back(search(root, s));
        
        return ans;
    }
};
