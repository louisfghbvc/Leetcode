// Give me the new sight view. O(N). 
// the tricky is map the node to new node.
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> _copy;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(!_copy.count(node)){
            _copy[node] = new Node(node->val);
            for(Node * v: node->neighbors){
                _copy[node]->neighbors.push_back(cloneGraph(v));
            }
        }
        return _copy[node];
    }
};
