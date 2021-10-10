// Each O(logN)

class StockPrice {
public:
    
    map<int, int> mp;
    multiset<int> st; // min and max heap
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp)){ // remove old
            int &old_val = mp[timestamp];
            st.erase(st.find(old_val));
        }
        st.insert(price);
        mp[timestamp] = price;
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
    }
};
