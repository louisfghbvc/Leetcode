// insert O(1)
// sum O(NK)
class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int tot = 0;
        for(auto &[k, v]: mp){
            if(k.substr(0, prefix.size()) == prefix) tot += v;
        }
        return tot;
    }
};

// insert O(K^2). avg O(K).
// sum O(1)
class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> mp;
    unordered_map<string, int> score;
    
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int diff = val - mp[key];
        string tmp = "";
        for(auto &c: key){
            tmp += c;
            score[tmp] += diff;
        }
        mp[key] = val;
    }
    
    int sum(string prefix) {
        return score[prefix];
    }
};

// use trie O(K). O(K)
