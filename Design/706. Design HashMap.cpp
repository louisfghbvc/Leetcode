// use linked list vector. also can just use array but too big.

class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<list<pair<int, int>>> mp;
    const int mx = 1e4;
    MyHashMap() {
        mp.resize(mx);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &lt = mp[key % mx];
        for(auto &[k, v]: lt){
            if(k == key){
                v = value;
                return;
            }
        }
        lt.push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &lt = mp[key % mx];
        for(auto &[k, v]: lt){
            if(k == key){
                return v;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &lt = mp[key % mx];
        for(auto i = lt.begin(); i != lt.end();++i){
            if(i->first == key){
                lt.erase(i);
                return;
            }
        }
    }
};
