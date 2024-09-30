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


// lazy update, O(1)
// we only mark the last index.

class CustomStack {
public:

    // idea:
    // how to improve the range update?
    // we can just using the index for lazy propagate.

    // size = 4
    // k = 3
    // [a b c d]
    //  0 0 x

    CustomStack(int maxSize) : maxSize(maxSize) {

    }
    
    void push(int x) {
        if (st.size() == maxSize) return;
        st.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        if (st.empty()) return -1;

        int lastIndex = st.size()-1;
        int ret = st.back() + inc[lastIndex]; 
        st.pop_back();

        // lazy update
        if (lastIndex > 0)
            inc[lastIndex-1] += inc[lastIndex];
        inc.pop_back();
        
        return ret;
    }
    
    void increment(int k, int val) {
        int i = min((int)inc.size(), k);
        if (i > 0)
            inc[i-1] += val;
    }

private:
    vector<int> st, inc;
    int maxSize;
};
