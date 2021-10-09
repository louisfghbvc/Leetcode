// shrink all string into one data structure.
// then backtracking. 

class Solution {
private:
    struct node{
        node* next[26] = {};
        string word = "";
    } *root;
    
    vector<string> res;
    vector<vector<char>> g;
    int m, n;
    
public:
    void add(string &s){
        node* tmp = root;
        for(char c: s){
            if(!tmp->next[c-'a']) tmp->next[c-'a'] = new node();
            tmp = tmp->next[c-'a'];
        }
        tmp->word = s;
    }
    
    void dfs(node* cur, int i, int j){
        if(!cur) return;
        if(cur->word.size()){ // find a word
            res.push_back(cur->word);
            cur->word = "";
        }
        if(i < 0 || i >= m || j < 0 || j >= n || g[i][j] == ' ') return;
        char c = g[i][j];
        g[i][j] = ' ';
        node* nxt = cur->next[c - 'a'];
        dfs(nxt, i-1, j);
        dfs(nxt, i+1, j);
        dfs(nxt, i, j-1);
        dfs(nxt, i, j+1);
        g[i][j] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        g = board;
        m = g.size(), n = g[0].size();
        
        // build trie
        root = new node();
        for(auto &s: words) add(s);
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dfs(root, i, j);
            }
        }
        
        return res;
    }
};
        
