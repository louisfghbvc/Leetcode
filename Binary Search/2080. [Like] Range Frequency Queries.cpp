// Range query. O(NlogN) preprocessing
// O(logN) qyery

class RangeFreqQuery {
public:
    vector<pair<int, int>> st; // value, index
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); ++i)
            st.push_back({arr[i], i});
        sort(st.begin(), st.end());
    }
    
    int query(int left, int right, int value) {
        // (value, right) - (value, left)
        return upper_bound(st.begin(), st.end(), make_pair(value, right)) - 
            lower_bound(st.begin(), st.end(), make_pair(value, left));
    }
};

// O(N) preprocess. O(logN) each
// segment divide, record each value index
class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); ++i)
            mp[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        // find [left, right) -> numbers
        auto &idx = mp[value]; 
        return upper_bound(idx.begin(), idx.end(), right) - 
            lower_bound(idx.begin(), idx.end(), left);
    }
};
