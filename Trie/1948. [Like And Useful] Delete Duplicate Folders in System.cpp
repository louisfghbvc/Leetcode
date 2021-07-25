// I am not sure the space complexity...
// but main idea is build tree sturcture and LC 652 find duplicate tree.
// hash tree to a string use post-order.

class Solution {
    vector<vector<string>> res;
public:
    struct trie_node{
        string name;
        map<string, trie_node*> next;
        bool isDel = false;
        trie_node(string n = "") : name(n) {};
    };
    
    void add(trie_node* root, vector<string> &path){
        trie_node* tmp = root;
        for(auto &s: path){
            if(!tmp->next[s]) tmp->next[s] = new trie_node(s);
            tmp = tmp->next[s];
        }
    }
    
    unordered_map<string, trie_node*> seen;
    string dedupe(trie_node* root){ // post-order, similar to LC 652
        string subFolder = "";
        for(auto &[name, next]: root->next){
            subFolder += dedupe(next);
        }
        if(subFolder.size()){ // not leaf
            if(seen.count(subFolder))
                seen[subFolder]->isDel = root->isDel = true;
            else
                seen[subFolder] = root;
        }
        return root->name + "," + subFolder;
    }
    
    vector<string> path;
    void gen_path(trie_node* root){
        if(root->isDel) return;
        path.push_back(root->name);
        res.push_back(path);
        for(auto &[_, next]: root->next){
            gen_path(next);
        }
        path.pop_back();
    }
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // 1. build tree
        // 2. dedupe
        // 3. parse ans
        
        trie_node* root = new trie_node();
        for(auto &p: paths)
            add(root, p);
        dedupe(root);
        for(auto &[_, next]: root->next)
            gen_path(next);
        
        return res;
    }
};
