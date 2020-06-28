// Find A Euler Path. Wow use dfs all path
// and when end add to main path
// deque can sort and pop_front and back fast.
// Think this case [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
// ans should be ["JFK","NRT","JFK","KUL"]
// and sort by lexigical
// O(E).

class Solution {
public:
    unordered_map<string, deque<string>> g;
    deque<string> res;
    
    void dfs(string u){
        while(g[u].size()){
            string v = g[u].front(); g[u].pop_front();
            dfs(v);
        }
        res.push_front(u);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto&e: tickets){
            g[e[0]].push_back(e[1]);
        }
        
        for(auto&[s, v] : g){
            sort(v.begin(), v.end());
            
        }
        
        dfs("JFK");
        
        return vector<string>(res.begin(), res.end());
    }
};
