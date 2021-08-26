// Awesome O(N). just use indegree and outdegree.

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // outdegree - indegree
        int diff = 1;
        istringstream in(preorder);
        string node;
        while(getline(in, node, ',')){
            if(--diff < 0) return false;
            if(node != "#") diff += 2;
        }
        return diff == 0;
    }
};

// Recursive simulate preorder
class Solution {
public:
    
    string s;
    bool dfs(int &i){
        string root = "";
        for(; i < s.size() && s[i] != ','; ++i)
            root += s[i];
        if(i > s.size()) return i == s.size();
        if(root == "#") return true;
        // left
        i++;
        if(!dfs(i)) return false;
        // right
        i++;
        if(!dfs(i)) return false;
        return true;
    }
    
    bool isValidSerialization(string preorder) {
        s = preorder;
        int i = 0;
        return dfs(i) && i == s.size();
    }
};
