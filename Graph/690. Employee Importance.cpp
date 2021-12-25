/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// just traversal the graph, and add the value
// O(N).

class Solution {
public:
    
    int dfs(Employee* root){
        if(!root) return 0;
        int res = root->importance;
        for(int v: root->subordinates)
            res += dfs(graph[v]);
        return res;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        // need a graph
        // id->Employee
        for(Employee* e: employees){
            graph[e->id] = e;
        }
        
        return dfs(graph[id]);
    }
    
private:
    unordered_map<int, Employee*> graph;
};
