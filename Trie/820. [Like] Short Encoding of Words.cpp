// Brute Force. O(N^2W)
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [&](auto &a, auto &b){
            return a.size() < b.size();
        });
        
        int n = words.size();
        vector<int> sz(n);
        for(int i = 0; i < n; ++i)
            sz[i] = words[i].size();
        
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int a = words[i].size(), b = words[j].size();
                if(words[j].compare(b-a, a, words[i]) == 0){
                    sz[i] = 0;
                    break;
                }
            }
        }
        
        int len = 0;
        for(int i = 0; i < n; ++i){
            if(sz[i]) len += sz[i] + 1;
        }
        
        return len;
    }
};


// Smart is revered word. Trie
// O(NlogN).

class Solution {
public:
    struct Trie{
        Trie* next[26] = {NULL};    
    };
    
    Trie *root;
    
    bool Insert(string &word){
        Trie *cur = root;
        bool ok = true;
        for(int j = word.size()-1; j >= 0; --j){
            if(cur->next[word[j]-'a'] && j == 0) ok = false;
            if(!cur->next[word[j]-'a'])
                cur->next[word[j]-'a'] = new Trie();
            cur = cur->next[word[j]-'a'];
        }
        return ok;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        root = new Trie();
        sort(words.begin(), words.end(), [&](auto &a, auto &b){
            return a.size() > b.size();
        });
        
        int res = 0;
        for(string &w: words){
            if(Insert(w)) res += w.size()+1;
        }
        
        return res;
    }
};
