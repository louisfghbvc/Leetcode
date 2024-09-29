class AllOne {
public:
    // goal: we can increase the key, decrease the key, get max key get min key
    // we want O(1), how?

    // idea:
    // double linked list!!
    // we just record the fre as list

    // using hash map to record list iterator


    AllOne() {
        
    }
    
    void inc(string key) {
        if (!keyIndex.count(key))
            keyIndex[key] = lt.insert(lt.begin(), Bucket(0, {key}));
        
        // increase the key into hashmap
        auto bucket = keyIndex[key], nextIdx = next(bucket);
        // next not existed in linked-list
        if (nextIdx == lt.end() || nextIdx->val > bucket->val+1)
            nextIdx = lt.insert(nextIdx, Bucket(bucket->val+1, {}));
        nextIdx->keys.insert(key);
        keyIndex[key] = nextIdx;

        // remove odd in list
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            lt.erase(bucket);
    }
    
    void dec(string key) {
        if (!keyIndex.count(key)) return;

        // decrease the key into hashmap
        auto bucket = keyIndex[key], prevIdx = prev(bucket);
        keyIndex.erase(key);
        if (bucket->val > 1) {
            // prevIdx not existed in linked-list
            if (bucket == lt.begin() || prevIdx->val < bucket->val-1)
                prevIdx = lt.insert(bucket, Bucket(bucket->val-1, {}));
            prevIdx->keys.insert(key);
            keyIndex[key] = prevIdx;
        }

        // remove odd in list
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            lt.erase(bucket);
    }
    
    string getMaxKey() {
        return lt.empty() ? "" : *lt.back().keys.begin();
    }
    
    string getMinKey() {
        return lt.empty() ? "" : *lt.front().keys.begin();
    }

private:
    struct Bucket {
        Bucket(int val, const unordered_set<string>& keys) : val(val), keys(keys) {}
        int val;
        unordered_set<string> keys;
    };
    list<Bucket> lt;
    unordered_map<string, list<Bucket>::iterator> keyIndex;
    
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
