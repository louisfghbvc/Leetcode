//36ms 19.4MB
class CustomStack {
public:
    vector<int> st;
    int mx;
    CustomStack(int maxSize) {
        mx = maxSize;
        st.clear();
    }
    
    void push(int x) {
        if(st.size() < mx)
            st.push_back(x);
    }
    
    int pop() {
        if(!st.size())
            return -1;
        int ret = st.back(); st.pop_back();
        return ret;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k && i < st.size(); ++i){
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
