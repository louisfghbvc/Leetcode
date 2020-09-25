// Very clear, O(1) snap. set. O(logN) get.
// wow, prev. next. tricky STL.
// and the main idea is just upperbound the snap id because the snap is from smaller. so just check.
// use STL map is easy to implement.

class SnapshotArray {
public:
    unordered_map<int, map<int, int>> mp;
    int cnt = 0;
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        mp[index][cnt] = val;
    }
    
    int snap() {
        return cnt++;
    }
    
    int get(int index, int snap_id) {
        auto it = mp[index].upper_bound(snap_id);;
        return it == mp[index].begin() ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
 
 
// Can also use map vector<pair>. and binary search pair.
class SnapshotArray {
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    int cnt = 0;
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        if(mp[index].empty() || mp[index].back().first != cnt)
            mp[index].push_back({cnt, val});
        else mp[index].back().second = val;
    }
    
    int snap() {
        return cnt++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(mp[index].begin(), mp[index].end(), make_pair(snap_id, INT_MAX));
        return it == mp[index].begin() ? 0 : prev(it)->second;
    }
};
