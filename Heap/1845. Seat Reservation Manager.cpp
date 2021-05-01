class SeatManager {
public:
    set<int> st;
    SeatManager(int n) {
        for(int i = 0; i < n; ++i)
            st.insert(i);
    }
    
    int reserve() {
        int x = *st.begin();
        st.erase(st.begin());
        return 1+x;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber-1);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
