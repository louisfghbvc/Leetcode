// a data Structure. avg O(1).
// trick, map record index, and when remove.
// swap last and val, map[last] and map[val], because get random arr same

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> mp;
    vector<int> arr;
    
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val)) return 0;
        mp[val] = arr.size();
        arr.push_back(val);
        return 1;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!mp.count(val)) return 0;
        int last = arr.back();
        mp[last] = mp[val];
        swap(arr[mp[val]], last);
        mp.erase(val);
        arr.pop_back();
        return 1;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = rand()%arr.size();
        return arr[n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
