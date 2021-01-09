// O(N^2M). very slow. but ac. 1548ms.
// precalculate all path. then fast bfs.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        
        int n = wordList.size();
        int ws = beginWord.size();
        
        vector<bool> vis(n);
        vector<vector<int>> g(n);
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int cnt = 0;
                for(int k = 0; k < ws; ++k) 
                    cnt += (wordList[i][k] != wordList[j][k]);
                if(cnt == 1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        } 
        
        queue<int> q;
        q.push(n-1);
        vis[n-1] = 1;
        int d = 1;
        while(q.size()){
            for(int qs = q.size()-1; qs >= 0; --qs){
                int u = q.front(); q.pop();
                if(wordList[u] == endWord) return d;
                for(int v: g[u]){
                    if(!vis[v]){
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
            d++;
        }
        
        return 0;
    }
};

// O(M^2N). more fast. but use set. 316ms
// use enum and use set to search.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        int ws = beginWord.size();
        unordered_set<string> vis;
        vis.insert(beginWord);
        
        int d = 1;
        while(q.size()){
            for(int qs = q.size()-1; qs >= 0; --qs){
                string u = q.front(); q.pop();
                if(u == endWord) return d;
                dict.erase(u);
                for(int i = 0; i < ws; ++i){
                    char t = u[i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        u[i] = c;
                        if(dict.count(u) && !vis.count(u)){
                            vis.insert(u);
                            q.push(u);
                        }
                    }
                    u[i] = t;
                }
            }
            d++;
        }
        
        return 0;
    }
};

// O(M^2N). use map and vis array. 152ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        
        int n = wordList.size();
        int ws = beginWord.size();
        
        unordered_map<string, int> id;
        for(int i = 0; i < n; ++i) id[wordList[i]] = i;
        
        vector<bool> vis(n); 
        queue<int> q;
        q.push(n-1);
        vis[n-1] = 1;
        
        int d = 1;
        while(q.size()){
            for(int qs = q.size()-1; qs >= 0; --qs){
                int u = q.front(); q.pop();
                if(wordList[u] == endWord) return d;
                for(int i = 0; i < ws; ++i){
                    char t = wordList[u][i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        wordList[u][i] = c;
                        if(!id.count(wordList[u])) continue;
                        int v = id[wordList[u]];
                        if(!vis[v]){
                            vis[v] = 1;
                            q.push(v);
                        }
                    }
                    wordList[u][i] = t;
                }
            }
            d++;
        }
        
        return 0;
    }
};

// Fastest O(M^N). Bi bfs. 36ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        
        int n = wordList.size();
        int ws = beginWord.size();
        
        unordered_map<string, int> id;
        for(int i = 0; i < n; ++i) id[wordList[i]] = i;
        
        if(!id.count(endWord)) return 0;
        int eid = id[endWord];
        
        vector<int> vis(n); 
        queue<pair<int, int>> cur, other;
        cur.push({n-1, 1});
        vis[n-1] = 1;
        
        other.push({eid, 2});
        vis[eid] = 2;
        
        int d = 1;
        while(cur.size()){
            if(cur.size() > other.size()) swap(cur, other);
            
            for(int qs = cur.size()-1; qs >= 0; --qs){
                auto [u, key] = cur.front(); cur.pop();
                for(int i = 0; i < ws; ++i){
                    char t = wordList[u][i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        wordList[u][i] = c;
                        if(!id.count(wordList[u])) continue;
                        int v = id[wordList[u]];
                        if(!vis[v]){
                            vis[v] = key;
                            cur.push({v, key});
                        }
                        else if(vis[v] != key) return d+1;
                    }
                    wordList[u][i] = t;
                }
            }
            d++;
        }
        
        return 0;
    }
};
