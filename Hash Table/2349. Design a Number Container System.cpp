class NumberContainers {
public:
    
    // unorderd_map -> number, record the index of set
    
    unordered_map<int, set<int>> mp;
    unordered_map<int, int> arr;
    
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        mp[number].insert(index);
        arr[index] = number;
    }
    
    int find(int number) {
        auto it = mp.find(number);
        if (it == mp.end()) return -1;
        
        while (it->second.size() && arr[*it->second.begin()] != number) {
            it->second.erase(it->second.begin());
        }
        
        if (it->second.empty()) return -1;
        return *it->second.begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
