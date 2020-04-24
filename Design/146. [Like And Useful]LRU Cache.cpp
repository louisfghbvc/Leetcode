//List + two map easy to uderstand. 184ms
class LRUCache {
public:
    list<int> lru;
    int c;
    unordered_map<int, int> k2v; // key - value
    unordered_map<int, list<int>::iterator> k2it; // key - iterator
    
    LRUCache(int capacity) : c(capacity) {}
    
    int get(int key) {
        if(!k2v.count(key)) return -1;
        updateLRU(key);
        return k2v[key];
    }
    
    void put(int key, int value) {
        if(k2v.size() == c && !k2v.count(key))
            release();
        updateLRU(key);
        k2v[key] = value;
    }
    
    void updateLRU(int key){
        if(k2v.count(key))
            lru.erase(k2it[key]);
        lru.push_front(key);
        k2it[key] = lru.begin();
    }
    
    void release(){
        k2v.erase(lru.back());
        k2it.erase(lru.back());
        lru.pop_back();
    }
};


//List + One Map, Faster. 144ms
class LRUCache {
public:
    int c;
    list<pair<int,int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> k2it; // key - lru iterator
    
    LRUCache(int capacity) : c(capacity) {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
    
    int get(int key) {
        if(!k2it.count(key)) return -1;
        // from lru's k2it position to lru.begin()
        lru.splice(lru.begin(), lru, k2it[key]);
        return k2it[key]->second;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            k2it[key]->second = value;
            return;
        }
        if(k2it.size() == c){
            int k = lru.back().first;
            k2it.erase(k);
            lru.pop_back();
        }
        lru.push_front({key, value});
        k2it[key] = lru.begin();
    }
};
