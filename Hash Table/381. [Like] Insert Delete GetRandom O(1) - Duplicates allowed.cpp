class RandomizedCollection {
public:
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool res = idx[val].size() == 0;
        arr.push_back(val);
        idx[val].insert(arr.size()-1);
        return res;
    }
    
    bool remove(int val) {
        if(idx[val].size() == 0) return false;
        
        if(arr.back() == val){
            idx[val].erase(arr.size()-1);
            arr.pop_back();
            return true;
        }
        
        // swap value to end
        int ori_end = arr.back();
        idx[ori_end].erase(arr.size()-1);
        
        int any_i = *idx[val].begin();
        idx[val].erase(any_i);
        
        swap(arr[any_i], arr.back());
        arr.pop_back();
        idx[ori_end].insert(any_i);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
    
private:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> idx;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
