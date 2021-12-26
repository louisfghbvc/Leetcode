// topology sort.
// O(N^2)

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // indegree
        unordered_map<string, int> need;
        // directed-graph
        unordered_map<string, vector<string>> adj;
        
        // do the topology sort
        for(int i = 0; i < recipes.size(); ++i){
            for(auto &com: ingredients[i]){
                adj[com].push_back(recipes[i]);
                need[recipes[i]]++;
            }
        }
        
        queue<string> q;
        unordered_set<string> done;
        for(auto &s: supplies){
            q.push(s);
        }
        
        while(q.size()){
            string u = q.front(); q.pop();
            done.insert(u);
            for(string &v: adj[u]){
                if(--need[v] == 0){
                    q.push(v);
                }
            }
        }
        
        vector<string> ans;
        for(auto &s: recipes){
            if(done.count(s))
                ans.push_back(s);
        }
        return ans;
    }
};

// some optimize. 
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        
        // indegree
        unordered_map<string, int> need;
        // directed-graph
        unordered_map<string, vector<string>> adj;
        
        // all can use
        unordered_set<string> st(supplies.begin(), supplies.end());
        
        // do the topology sort
        for(int i = 0; i < recipes.size(); ++i){
            need[recipes[i]] = 0;
            // add edge only non-seen
            for(auto &com: ingredients[i]){
                if(!st.count(com)){
                    adj[com].push_back(recipes[i]);
                    need[recipes[i]]++;
                }
            }
        }
        
        // bfs
        queue<string> q;
        for(auto &[s, f]: need){
            if(f == 0) q.push(s);
        }
        while(q.size()){
            string u = q.front(); q.pop();
            ans.push_back(u);
            for(string &v: adj[u]){
                if(--need[v] == 0){
                    q.push(v);
                }
            }
        }
        
        return ans;
    }
};
