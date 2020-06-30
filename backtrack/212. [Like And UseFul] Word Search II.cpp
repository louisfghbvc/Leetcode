// shrink all string into one data structure.


class Solution {
public:
    struct trieNode{
        trieNode* next[26];
        string word;
        trieNode(){
            memset(next, 0, sizeof next);
            word = "";
        }
    };
    
    trieNode* buildTrie(vector<string>& words){
        trieNode* root = new trieNode();
        for(auto &wd: words){
            trieNode *tmp = root;
            for(int i = 0; i < wd.size(); ++i){
                if(tmp->next[wd[i]-'a'] == NULL){
                    tmp->next[wd[i]-'a'] = new trieNode();
                }
                tmp = tmp->next[wd[i]-'a'];
            }
            tmp->word = wd;
        }
        
        return root;
    }
    
    int m, n;
    vector<string> res;
    vector<vector<char>> g;
    const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(int x, int y, trieNode* root){
        char c = g[x][y];
        if(c == '#' || root->next[c-'a'] == NULL) return;
        root = root->next[c-'a'];
        if(root->word.size()){
            res.push_back(root->word);
            root->word = "";
        }
        
        g[x][y] = '#';
        for(int i = 0; i < 4; ++i){
            int nx = x+dir[i][0], ny = y+dir[i][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            dfs(nx, ny, root);
        }
        g[x][y] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        m = board.size(), n = board[0].size();
        g = board;
        trieNode* root = buildTrie(words);
        // print(root);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dfs(i, j, root);
            }
        }
        
        return res;
    }
    
    void print(trieNode* root){
        if(root->word != "" ) {
            cout << root->word << endl;
            return;
        }
        for(int i= 0; i < 26; ++i){
            if(root->next[i]){
                print(root->next[i]);
            }
        }
        
    }
};
