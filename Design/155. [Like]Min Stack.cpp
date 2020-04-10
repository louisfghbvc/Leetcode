//32-40ms 14.4MB
class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> st;
    int mn;
    MinStack() {
        mn = INT_MAX;
    }
    
    void push(int x) {
        mn = min(mn, x);
        st.push({x, mn});
    }
    
    void pop() {
        if(st.top().second == mn){
            st.pop();
            mn = st.empty()? INT_MAX :st.top().second;
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
